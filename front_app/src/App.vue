<template>
    <div>
        <Navbar v-on:toggle-settings="togglePage"></Navbar>
        <b-container>
            <component v-bind:is="page"></component>
        </b-container>
    </div>
</template>

<script>
    import Dashboard from './components/Dashboard.vue'
    import Settings from './components/Settings.vue'
    import Navbar from './components/Navbar.vue'


    export default {
        name: 'app',
        components: {
            Dashboard,
            Settings,
            Navbar
        },
        data() {
            return {
                page: 'Dashboard'
            }
        },
        methods: {
            togglePage: function () {
                if (this.page == 'Dashboard') {
                    this.page = 'Settings';
                } else {
                    this.page = 'Dashboard'
                }

            }
        },
    }
</script>
