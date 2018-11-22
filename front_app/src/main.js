import Vue from 'vue'
import App from './App.vue'
import BootstrapVue from 'bootstrap-vue'
import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap-vue/dist/bootstrap-vue.css'
import VueNativeSock from 'vue-native-websocket'
import store from './store'
import { library } from '@fortawesome/fontawesome-svg-core'
import { faCog } from '@fortawesome/free-solid-svg-icons'
import { FontAwesomeIcon } from '@fortawesome/vue-fontawesome'

library.add(faCog);


Vue.use(BootstrapVue);
Vue.config.productionTip = false;
Vue.use(VueNativeSock, 'ws://test.local:81', {
    reconnection: true, // (Boolean) whether to reconnect automatically (false)
    // reconnectionAttempts: 10, // (Number) number of reconnection attempts before giving up (Infinity),
    // reconnectionDelay: 1000, // (Number) how long to initially wait before attempting a new (1000)
    format: 'json',
    store: store
});
Vue.use(require('vue-moment'));
Vue.component('font-awesome-icon', FontAwesomeIcon);

var app = new Vue({
  store,
  render: h => h(App)
}).$mount('#app');
