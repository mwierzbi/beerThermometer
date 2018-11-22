<template>
    <div>
        <b-row>
            <b-col>
                <GChart
                        :settings="{ packages: ['gauge'] }"
                        type="Gauge"
                        :data="chartData"
                        :options="chartOptions"
                />
            </b-col>
        </b-row>
        <b-row>
            <b-col>
                <b-form-group id="fieldsetHorizontal"
                              horizontal
                              :label-cols="4"
                              breakpoint="md"
                              label="Temperature of step"
                              label-for="target">
                    <b-form-input v-model.number="target"
                                  id="target"
                                  type="number"
                                  placeholder="Temperature of step"></b-form-input>
                </b-form-group>

            </b-col>
        </b-row>
    </div>
</template>

<script>
    import { GChart } from 'vue-google-charts'
    export default {
        name: "Gauge",
        components: {
            GChart
        },
        props: ['id', 'value'],
        computed: {
            chartData: function() {
              return [
                  ['Label', 'Value'],
                  ['°C', this.value],
              ]
            },
            chartOptions: function() {
                return {
                    width: 500, height: 500,
                    greenFrom: this.target-5, greenTo: this.target+5, greenColor: "rgb(199, 1, 1)",
                    redFrom: this.target-1, redTo: this.target+1, redColor: "Green",
                    yellowFrom:this.target-2, yellowTo: this.target+2,
                    minorTicks: 10,
                    majorTicks: [0,10,20,30,40,50,60,70,80,90,100]
                }

            },
            target: {
                get () {
                    console.log(this.$store.getters.sensor(this.id));
                    return this.$store.getters.sensor(this.id).target;
                },
                set (value) {
                    this.$store.commit('sensorTarget', {id: this.id, target:value});
                }
            }
        }
    }
</script>

