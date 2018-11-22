import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

const store =  new Vuex.Store({
    strict: true,
    state: {
        socket: {
            isConnected: false,
            message: [],
            reconnectError: false,
            updateAt: new Date()
        },
        sensors: []
    },
    getters: {
        activeSensors: state => {
            return state.sensors.filter(sensor => sensor.active);
        },
        sensor: (state) => (id) => {
            return state.sensors.find(sensor => sensor.id = id);
        }
    },
    mutations: {
        toggleSensor(state, sensorId) {
            let sensorIndex = state.sensors.findIndex(sensor => (sensor.id == sensorId));
            let sensor = state.sensors[sensorIndex];
            sensor.active = !sensor.active;
            Vue.set(state.sensors,sensorIndex, sensor);
        },
        SOCKET_ONOPEN(state, event) {
            Vue.prototype.$socket = event.currentTarget;
            state.socket.updateAt = new Date();
            state.socket.isConnected = true;
            let self = this;
            let checkUpdate = setInterval(function () {
                let now = new Date();
                if (now.getTime() - self.state.socket.updateAt.getTime() > 10000) {
                    Vue.prototype.$socket.close();
                    self.state.socket.isConnected = false;
                    clearInterval(checkUpdate);
                }
            }, 1000);
        },
        SOCKET_ONCLOSE(state, event) {
            state.socket.isConnected = false;
        },
        SOCKET_ONERROR(state, event) {
            console.error(state, event);
        },
        // default handler called for all methods
        SOCKET_ONMESSAGE(state, message) {
            state.socket.message = message;
            state.socket.updateAt = new Date();
            message.forEach(function(item){
                let sensor = state.sensors.find(sensor => (sensor.id == item.id));
                if (sensor == undefined) {
                    item.active = false;
                    item.target = 68;
                    state.sensors.push(item);
                } else {
                    sensor.value = item.value;
                }
            });
        },
        // mutations for reconnect methods
        SOCKET_RECONNECT(state, count) {
            console.info(state, count);
        },
        SOCKET_RECONNECT_ERROR(state) {
            state.socket.reconnectError = true;
        },
        initialiseStore(state) {
            if (localStorage.getItem("store")) {
                this.replaceState(
                    Object.assign(state, JSON.parse(localStorage.getItem("store")))
                );
            }
        },
        sensorTarget(state, data) {
            let sensor = state.sensors.find(sensor => (sensor.id == data.id));
            sensor.target = data.target;
        }
    },
    actions: {}
});

// Init store from localStorage on load
store.commit("initialiseStore");

// Update localstorage for every mutation
store.subscribe((_mutation, state) => {
    localStorage.setItem("store", JSON.stringify(state));
});

export default store;
