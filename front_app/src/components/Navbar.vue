<template>
    <b-navbar toggleable="md" type="dark" :variant=color>

        <b-navbar-nav class="">
            <b-navbar-brand href="#">Beer temperature</b-navbar-brand>
            <b-nav-text>Updated {{lastUpdate}} seconds ago</b-nav-text>
        </b-navbar-nav>
        <b-navbar-nav class="ml-auto">
            <b-nav-text>{{currentTime | moment('HH:mm:ss')}}</b-nav-text>
            <b-nav-item v-on:click="$emit('toggle-settings')"> <font-awesome-icon icon="cog" /></b-nav-item>
        </b-navbar-nav>




    </b-navbar>
</template>

<script>
    export default {
        name: "Navbar",
        data(){
            return {
                lastUpdate: 0,
                currentTime: new Date()
            }
        },
        computed: {
            color: function () {
                return this.$store.state.socket.isConnected ? 'dark' : 'danger';
            }
        },

        created() {
            let self = this;
            setInterval(function () {
               self.lastUpdate = self.$moment().diff(self.$moment(self.$store.state.socket.updateAt), 'seconds');
               self.currentTime = new Date();
            }, 1000);
        }
    }
</script>

<style scoped>

</style>