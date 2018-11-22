<template>
    <b-row align-content="center">
        <b-col v-for="item in items" lg="6" style="min-height: 300px; min-width: 300px">
            <div>
                <settings-sensor :id=item.id :value="item.value" :active=item.active></settings-sensor>
            </div>
        </b-col>
    </b-row>
</template>
<script>
    import SettingsSensor from './SettingsSensor.vue'
    export default {
        name: 'Settings',
        components: {SettingsSensor},
        comments: {
            SettingsSensor
        },
        data() {
            return {
                test: 'test'
            }
        },
        computed: {
            items: function () {
                return this.$store.state.sensors
            }
        }
    }
</script>
