//�����dream-blade,��ˮ¥֮��skill
//edit by Trf
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit F_SSERVER;
//inherit F_FUNCTION;
void seven(object me,object victim,object weapon,int damage);
void lockman(object me,object victim,object weapon,int damage);
void four_kill(object me,object victim,object weapon,int damage);
int five_kill(object me,object victim,object weapon,int damage);
void lovekill(object me,object victim,object weapon,int damage);
void power_slash(object me,object victim, object weapon,int damage);
void heartkill(object me,object victim,object weapon,int damage);
void dream(object me,object victim,object weapon,int damage);
void fast(object me,object victim,object weapon,int damage);
void disenforce(object me, object victim, object weapon, int damage);
void two(object me,object victim,object weapon,int damage);

mapping *action = ({
//1-8�����齣
//1
([ "action" :NOR"                                  "HBRED"==��һ���ľ���=="NOR"\n"NOR+
             HIW"$N�ђ���$w"HIW"���֣�������ˮ������ͳ�������������������������һ���ܳ�������\n"
            +HIW"��һ�����ǹ��꣬Ҳ���Ƕ��ǣ�����һ�ֻ꾡������Ʈ����ת���˵���ٶȣ��׵���㵣���$n"HIW"������"NOR,
               "dodge"  :        -15,
               "move"   :        -30,
               "damage" :        180,
               "parry"  :          5,
               "force"  :        200,
               "post_action":  (: two :),
               "damage_type":  "���Ž���",
]),
//2
([ "action" :NOR"                                  "HBRED"==��һ��������=="NOR"\n"NOR+
             HIW"$w"HIW"ӭ��������������һ��������â���������¸����˼�����â�����������ÿ�������\n"
            +HIW"һ�ڱƽ��ľ��̣����罣����ļ�Ī��������$n"HIW"����ػ���$n"HIW"���У�ֱ������"NOR,
               "dodge"  :         20,
               "move"   :          0,
               "damage" :        200,
               "parry"  :         10,
               "force"  :        200,
               "post_action":  (: two :),
               "damage_type":  "��Թ����",
]),
//3
([ "action" :NOR"                                  "HBRED"==��һ������Ȼ=="NOR"\n"NOR+
             HIW"$N�ľ������ȣ��ƺ�һ��������$w"HIW"�Ѵ̳�������⣬��һ������Ĺ��Σ�������׼���\n"
            +HIW"ֱ��$n����Ӱ������ĺޣ�ǳǳ���Σ��������µ���\�ۣ�"NOR,
               "dodge"  :        -10,
               "move"   :          0,
               "damage" :        180,
               "parry"  :          0,
               "force"  :        250,
               "post_action":  (: lovekill :),
               "damage_type":  "���齣��",
]),
//4
([ "action" :NOR"                                  "HBRED"==��һ���ķ���=="NOR"\n"NOR+
             HIW"$N��һ�����⾳���޷��������ͼ����������ȥ���ݣ��Ȳ��ǿ졢�಻���桢Ҳ���Ǿ�������ֻ��������\n"
            +HIW"����һ��ֻӦ�����У���Ӧ�����޵Ľ�����$n"HIW"��㶵�������ɲ�Ǽ����ᣡ"NOR,
               "dodge"  :         10,
               "move"   :         30,
               "damage" :        200,
               "parry"  :         10,
               "force"  :        200,
               "post_action":  (: lockman :),
               "damage_type":  "Ī������",
]),
//5
([ "action" :NOR"                                  "HBRED"==��һ���Ĳ���=="NOR"\n"NOR+
             HIW"$NХ����������ӥ���������Ӱ�����������У����ƺ��е����������಻��������â������ҹ�ǰ��\n"
            +HIW"��$n"HIW"��֪��������ܣ�ɲ�Ǽ佦���˵���Ѫ�⣡"NOR,
               "dodge"  :        -10,
               "move"   :          0,
               "damage" :        180,
               "parry"  :          0,
               "force"  :        250,
               "post_action":  (: four_kill :),
               "damage_type":  "������",
]),
//6
([ "action" :NOR"                                  "HBRED"==��һ��������=="NOR"\n"NOR+
             HIW"$N���е�$w"HIW"����һ�����������⣬���ľ������������ֵ���һĨ��ɫ��������죬��Ӱ���Σ�\n"
            +HIW"���������������ޱȣ���$n"HIW"���Եֵ��������ķ�â���뼡�ǣ�"NOR,
               "dodge"  :        -20,
               "move"   :        -20,
               "damage" :        200,
               "parry"  :         20,
               "force"  :        200,
               "post_action":  (: power_slash :),
               "damage_type":  "��������",
]),
//7
([ "action" :NOR"                                  "HBRED"==��һ���İ���=="NOR"\n"NOR+
             HIW"�������ϵĽ������ͷ·�ͳ�������������ɢ�������ģ���翵Ľ���������Զ�����˵ĺ�����\n"
            +HIW"����������˵һ��˵�����İ���޿��κεİ��ȴ�ִ���˵������������"NOR,
               "dodge"  :        -10,
               "move"   :        -10,
               "damage" :        200,
               "parry"  :        -70,
               "force"  :        500,
               "post_action":  (: seven :),
               "damage_type":  "��Թ����",
]),
//8
([ "action" :NOR"                                  "HBRED"==��һ���ļ�į=="NOR"\n"NOR+
             HIW"�����Ľ�����$n"HIW"��������������ᣬ����һ��������һ�����Ͱ�$n"HIW"�ļ��䵼����Ҫ���˵���һ�θ�����\n"
            +HIW"�Ѱ��绻�ϻƻ�ļ�į����$n"HIW"��ʧȥ�Լ��ĸо����������µ�΢����ƽ���£����Ҳ������֣�"NOR,
               "dodge"  :          0,
               "move"   :          0,
               "damage" :        250,
               "parry"  :          0,
               "force"  :        250,
               "post_action":  (: lovekill :),
               "damage_type":  "��Թ����",
]),
});


mapping query_action(object me,object weapon)
{
        string actionn;
        int limit;
        int skill_level = me->query_skill("love-sword",1);
        if (!userp(previous_object())) skill_level=120;

        limit= skill_level/10;
       if (limit < 2 )
                return action[0];
       else if (limit < 4 )
                return action[random(2)];
       else if (limit < 6 )
                return action[random(3)];
       else if (limit < 7 )
                return action[random(4)];
       else if (limit < 9 )
                return action[random(5)];
       else if (limit < 10 )
                return action[random(6)];
       else if (limit < 11 )
                return action[random(7)];
       else
                return action[random(8)];
}
void two(object me,object victim,object weapon,int damage)
{
     int bell,sk,mk,mk1,i;
     bell = me->query("bellicosity",1);
     sk= me->query_skill("love-sword", 1);
     if (!userp(previous_object())) sk=120;
     mk = me->query("MKS");
     if(mk<8500) {damage = 3*sk;mk1=5;}
     else 
     	if(mk<9000) {damage = 3*sk;mk1=4;}
     else 
     	if(mk<9500) {damage = 3*sk;mk1=3;}
     else 
     	if(mk<10000) {damage = 3*sk;mk1=2;}
     else {damage = 3*sk;mk1=1;}

	if( bell<100 
//	&& me->query_skill_mapped("sword") == "love-sword"  
//	&& me->query_skill_mapped("parry") == "dream-blade"  
	&& damage>0)
 	{
   		message_vision(HIW"\n       ����һ��磬����һ��\�̣����þ�������ˮ��ô��Ȼ����������������Ҳ����������������ɱ��\n\n"
                	       HIW"                          �������⻪����������ã��߸����ϣ�����Ʈ��\n\n"
                  	       HIW"                   $nֻ��������⻪�·�����Լ�ü��䣬�ַ·���������翼�\n\n"
                  	       HIW"                   ���ı仯�������ѳ�Խ�����������ļ��ޣ������������޷�����\n\n"NOR,me,victim);
	        for(i=0;i<=mk1;i++)
        	{
        	  	victim->receive_damage("qi",damage);
         		 COMBAT_D->report_status(victim);
       		}
 	}
}
void lovekill(object me,object victim,object weapon,int damage)
{
 int bell,mk,skillb;
 bell = me->query("bellicosity");
 mk = (int)me->query("MKS",1);
 skillb = (int)me->query_skill("love-sword",1);
 if (!userp(previous_object())) skillb=120;
if(!me->query_temp("lovekill"))
 {
	 if( random(100) < 60 && mk < 9000 && bell < 100 && damage>0)
   	{

	message_vision("

"HIW"                        "BLINK"�� �������������ˣ��������������� ��"NOR"

"HIY"--����Ը���������ڵ�ԸΪ����֦--"NOR"
"HIR"                                       �����ݺᣬ��Ӱٿ�����·�ն�������¾���\n"NOR,me,victim);
             victim->receive_damage("qi",skillb);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--�������ڳ���ʱ�������ڳ���ĺĺ--"NOR"
"HIR"                                       ƽ��һ����������㯣��·���������³���\n"NOR,me,victim);
             victim->receive_damage("qi",skillb);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--���ĵؽ�����ʱ��ֻ����˼�޾���--"NOR"
"HIR"                                       ������ƣ����ö�Ŀ���·���������»���\n"NOR,me,victim);
             victim->receive_damage("qi",skillb);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--�´������ղ��ڣ�Ϊ����������--"NOR"
"HIR"                                       ������˸������Ʈ�����·𶯳�����������\n"NOR,me,victim);
             victim->receive_damage("qi",skillb);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--���鲻�ƶ���࣮һ�绹��ǧ����\--"NOR"
"HIR"                                       ����¶����ҷ����𣬷·�ó�����������\n"NOR,me,victim);
             victim->receive_damage("qi",skillb);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--����ɴ���׷�䣮ֻ�ǵ�ʱ���Ȼ--"NOR"
"HIR"                                       ����һ�����������ǣ��·��ճ������¹⻪\n"NOR,me,victim);
             victim->receive_damage("qi",2*skillb);
             victim->start_busy(random(2));
             COMBAT_D->report_status(victim);
   	}
  }
  me->delete_temp("lovekill");
}
//busy����,���й���֮����
void lockman(object me,object victim,object weapon,int damage)
{
        int mk,mecor,victimcor;
        int sk = me->query_skill("love-sword",1);
        if (!userp(previous_object())) sk=120;
        mk = (int)me->query("MKS",1);
        mecor = me->query("cor") + me->query("cps") 
              + me->query("combat_exp")/100000 ;
        victimcor = victim->query("cor") + victim->query("cps") 
                  + victim->query("combat_exp")/100000 ;
        if(!me->query_temp("lockman") && me->query("force") > 50 
        && mk < 10000 && damage > 0)
        {
               me->set_temp("lockman",1);
               me->add("neili",-50);
               victim->start_busy(2);
               if( random(mecor) >= random(victimcor))
                {
                   message_vision(CYN"�����Ѷ�ȥ$n"CYN"����־��ʹ$n"CYN"����������������ߵĲ�ϧ���Լ�������ɱȥ����\n"NOR , me , victim );
                   victim->receive_damage("qi",3*sk,me);
 //                  victim->receive_damage("sen",1*(victim->query("max_sen")/10));
                   victim->receive_damage("jing",1*(victim->query("max_jing")/10));
                   if (damage <= 0)
                   COMBAT_D->report_status(victim, 1);
                }
                else{
                        message_vision(sprintf(CYN"���������������飬$n"CYN"���ý����ѽ�֯��һ��ɱ�������\n"NOR),me,victim);
                }
         }
         else{
                 me->delete_temp("lockman");
         }
}
void four_kill(object me,object victim,object weapon,int damage)
{
 int bell,mk;
 bell = me->query("bellicosity");
 mk = (int)me->query("MKS",1);
 damage= (int)(me->query_skill("love-sword", 1));
 if (!userp(previous_object())) damage=120;
 if(!me->query_temp("four_kill"))
 {
  if( random(100) < 60 && mk < 10000 && bell < 200  && damage>0)
   {
me->set_temp("four_kill",1);
message_vision("\n
                             "HIG"�����氮���森������������"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage);
             COMBAT_D->report_status(victim);

message_vision("
                             "HIB"�����氮��֣��������źޡ�"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage);
             COMBAT_D->report_status(victim);

message_vision("
                             "HIR"���鰮ûԵ�ݣ�һ�������ˡ�"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage);
             COMBAT_D->report_status(victim);
message_vision("
                             "HIC"���鰮��į�ˣ���į��������"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage);
             victim->start_busy(random(2)+1);
             COMBAT_D->report_status(victim);
             call_out("five_kill", 1 ,me);
   }
 }
  me->delete_temp("four_kill");
}
int five_kill(object me,object victim,object weapon,int damage)
{
 int bell = me->query("bellicosity");
 weapon=me->query_temp("weapon");
   message_vision("\n
  "HIY"       $N�����뽣�ѿ�ʼ���˶�����һ�ּ��������������Ķ����������Ƿ���ô��Ȼ\n
  "HIY"                    $N��ͫ����������"+weapon->name()+""HIY"�������Ĵ��˳���\n
  "HIY"             �����˼��Ĳ�λ���˳������̳�ʱ��Ȼ���������˼��ı仯\n
  "HIY"         ���ϸ���û����������һ��������û���κ�����˭��ȥ����һ��������ȥ����\n\n"NOR,me,victim);
 if(bell < 50 && random(10)>4)
  {

   message_vision(HIR"              Ѫ��ҫ���ֲ��ã����õ��������ǣ�����һ�ּ��ţ�Ѫ��Ҳ�ܿ������\n"NOR, me);
        victim->add("neili",-1*victim->query("max_neili")/5);
        victim->receive_damage("qi",1*(victim->query("max_qi")/5));
//        victim->receive_damage("sen",1*(victim->query("max_sen")/5));
        victim->receive_damage("jing",1*(victim->query("max_jing")/5));
        victim->start_busy(2);
        me->add("neili",-1*(me->query("neili")/10));
  }
   else
  {
   message_vision(HIR"              Ѫ��ҫ���ֲ��ã����õ��������ǣ�����һ�ּ��ţ�Ѫ��Ҳ�ܿ������\n"NOR, me);
        victim->add("neili",-1*victim->query("max_neili")/10);
        victim->receive_damage("qi",1*(victim->query("max_qi")/10));
//        victim->receive_damage("sen",1*(victim->query("max_sen")/10));
        victim->receive_damage("jing",1*(victim->query("max_jing")/10));
        victim->start_busy(1);
        me->add("neili",-1*(me->query("neili")/10));
  }
}
void power_slash(object me,object victim, object weapon,int damage)
{
 object *enemy,target,env;
 int i,j,bell;
 bell = me->query("bellicosity");
 damage = victim->query("eff_qi")/20;
 env = environment(me);
 enemy=me->query_enemy();
 i=sizeof(enemy);
 for(j=0;j < i;j++){
 victim=enemy[j];
    if( env == environment(victim) && bell < 100)
    {
     victim->receive_wound("qi", damage);
     switch(random(4)+1)
    {
     case 1 :
     message_vision(sprintf("\n                               "HBCYN"��������˾���׷�䣮��\n"NOR),me,victim);
     message_vision(sprintf(HIW"��ô�����һ���������Ǵ���$n�����������ȥ������δ�������һ��������޵���һ������ \n"NOR),me,victim);
     break;
     case 2 :
     message_vision(sprintf("\n                               "HBWHT"�������첻�������ˣ���\n"NOR),me,victim);
     message_vision(sprintf(HIW"��ս��⻯����⣬�������£�����������$n�У������˽���������һ������\���� \n"NOR),me,victim);
     break;
     case 3 :
     message_vision(sprintf("\n                               "HBMAG"���������Թſ���ޣ���\n"NOR),me,victim);
     message_vision(sprintf(HIW"һƬ��ɫ����������˰����$n��$n����û��ʹ�࣬û�л��⣬����û��һ����飮��\n"NOR),me,victim);
     break;
     case 4 :
     message_vision(sprintf("\n                               "HBGRN"�����鵽���Թ�ɣ���\n"NOR),me,victim);
     message_vision(sprintf(HIW"��һ��֮����$n�޷����㣬�����������һ��ħ�ǣ�������ע������ôһ�������������\n"NOR),me,victim);
     break;
    }
     COMBAT_D->report_status(victim);
    }
  }
}
void seven(object me,object victim,object weapon,int damage)
{
  int i,mk,da;
  int sk = me->query_skill("love-sword",1);
  if (!userp(previous_object())) sk=120;
  mk = (int)me->query("MKS",1);
  weapon=me->query_temp("weapon");
  if(mk < 10000 ) { da = 130; }
  else { da=100; }
 if( me->query("bellicosity",1) < 200 && mk<10000)
 {
    message_vision(HIW"\n      $N�����յ�"+weapon->name()+""HIW"�·���ɱ�˵�������������������һ�У���һ�в������죮������׼ȷ\n\n"
                 HIW"        $n���еĶ�����������һ��ʹ��ʱ��Ȼ��ȫ��ͣ�٣�Ȼ�����ͽ�����һƬ����\n\n"
                 HIW"                    ����Ľ�Ӱ�������Ѫ����������ת������ת�죬�ɴ����\n\n"
                 HIW"               ��Ȼ�ֻ���һ��ƥ����Ĳʺ죬��ɫ�ʺ죬�߽�����ɶ��ˣ�ǧ����\n\n"NOR,me,victim);
    for(i=1;i<=7;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf(HIR"                       --<<��>>��������粻�����������������Ӧ����--\n"NOR),me,victim);
     break;
     case 2:
message_vision(sprintf(YEL"                       --<<��>>�������������ã�������ɣ�����������--\n"NOR),me,victim);
     break;
     case 3:
message_vision(sprintf(HIY"                       --<<��>>�����������Ъ��������£��������˵--\n"NOR),me,victim);
     break;
     case 4:
message_vision(sprintf(HIG"                       --<<��>>������������ʣ��������ǿ�ֻ���ζ--\n"NOR),me,victim);
     break;
     case 5:
message_vision(sprintf(HIB"                       --<<��>>���������Ҳ�˻����ͽ����������ȥ��ʱ--\n"NOR),me,victim);
     break;
     case 6:
message_vision(sprintf(CYN"                       --<<��>>�������������ߣ�������ϣ��������˼�--\n"NOR),me,victim);
     break;
     case 7:
message_vision(sprintf(MAG"                       --<<��>>��������׷��˼��������������˼��\--\n"NOR),me,victim);
     break;
     }
     if( sk > random(30)+100)
     {
message_vision(sprintf(HIC"$n��$N����ɫ����������ȫ�������˺����ۣ�\n"NOR),me,victim);
          victim->receive_wound("qi",da,me);
          COMBAT_D->report_status(victim,1);
     }
     else
     {
           message_vision(sprintf(WHT"$n"+WHT"����ֹˮ��������$N"+WHT"�Ľ��ƣ�\n"NOR),me,victim);
     }
   }
 }
}
/*
//ɱ��������8000����׼,8000-10000�Ż�ǿ,10000���ϻ��кܶั��������,����������ǿ
//�齣��һ����ɫ������





//ɱ��С��200,ɱ����С��10000,����Լ6��,�˺�Լ480


//������ɱ,ɱ����С��50�����Ż��,����Լ55%




//�������������20%






//.............................................................
//dream-dest��fire-dance�ڵ����ϱ�ʱ�Ի����жϽ�������
void dream(object me,object victim,object weapon,int damage)
{
     int mk,damagea,damage1,bell,sena,senb;
     mk = (int)me->query("MKS",1);
     if(mk < 10000)  {damagea = mk/10;  }     //mk<10000  ,����Լ��800-990
     else { damagea = mk/50; }                //mk>10000  ,����Լ��200-600(mk=30000)
                                              //ɱ����Խ��,�����Ż�ǿ
     damage1= random(damagea)+damagea;
     bell = me->query("bellicosity",1);
     sena = victim->query("max_sen");
     senb = sena/10;
  if( bell<100 && me->query_skill_mapped("sword") == "love-sword"  && me->query_skill_mapped("parry") == "dream-blade" && damage>0 )
   {
    if(random(100)>50)
     {
       message_vision(HIW"\n
         $N��������Ҹ����һ�������⣮һ����һ���ĵ��⣮���������ʢ��\n
        "HIW"��ؼ�Ʈҷ��һ���������⣬�����ƻã���������¹�Ͷ������Ĵ� \n
               "HIW"��һ�������졢���١����򵥡���ȥ��ƽ�����森���� \n
               "HIW"Ȼ��ȴ�ǡ���˼���Ρ�һǧ��һʽ�����еľ�����ɱ�У�\n
                           "HIW"��"HIR"�赶����������ն"HIW"�� \n\n"NOR, me);

              me->add("force",-random(300));
              victim->receive_damage("qi",1*damage1);
              victim->receive_damage("sen",senb);
              COMBAT_D->report_status(victim);
      }
      else
      {
        message_vision(HIW"\n
           һ��է�������Ķ���ϸ������������Ѫ�ڶ��ĺ�⣬�Ե���͸�˳���\n
                    "HIW"Ѫ���ĵ�������̫�����°�������$n����Χ\n
              "HIW"$nֻ�����ֿ졢���桢�־������ޡ���������ꡢ����һ��\n
                                  "HIW"��"HIC"���쳾·"HIW"��\n"NOR,me,victim);

        message_vision(HBRED"\n$N�ķ������$n���˷��磬��ʧ�ڷ��쳾֮�У�\n"NOR,me,victim);
        victim->start_busy(random(4)+1);
        victim->receive_damage("qi",1*damagea);
      }
   }
}


//��˼���ε����İ�����
void heartkill(object me,object victim,object weapon,int damage)
{
  int i;
  message_vision(HIC"\n\n\tֻ��$N���������ŵ�ʽһ�䣬������������ҫ�۵Ĺ�â�������һƬãã�ĵ�Ļ\n\n"
                 HIW"\t����"BLINK""HIR"   �����쳾����˼����  "NOR""HIW"  ����\n\n"NOR,me,victim);
    for(i=1;i<=8;i++)
  {
    switch(i)
     {
     case 1:
message_vision(sprintf(HIY"$N���絶���Ȼ���ˣ�ʹ��"HIR"�����쳾"HIW"֮"+NOR+""+RED+"�������ɡ�"+NOR+""+HIY+"������������㹥��$n��\n"NOR),me,victim);
     break;
     case 2:
message_vision(sprintf(HIY"$N�ķ����ң��������ʹ��"HIR"�����쳾"HIW"֮"+NOR+""+GRN+"�������ҡ�"+NOR+""+HIY+"�����������˰����$n��\n"NOR),me,victim);
     break;
     case 3:
message_vision(sprintf(HIY"$N������㲣���Ȼ��ʧ��ʹ��"HIR"�����쳾"HIW"֮"YEL"����������"+NOR+""+HIY+"�������������ϯ��$n��\n"NOR),me,victim);
     break;
     case 4:
message_vision(sprintf(HIY"$N�Ĳ����ɣ������ᣬʹ��"HIR"�����쳾"HIW"֮"MAG"��ʧ���֡�"+NOR+""+HIY+"�������������û�$n��\n"NOR),me,victim);
     break;
     case 5:
message_vision(sprintf(HIY"$N�Ĳ�������ʧ�����ǣ�ʹ��"HIR"�����쳾"HIW"֮"+NOR+""+CYN+"����������"+NOR+""+HIY+"����������Ȱ��Ի�$n��\n"NOR),me,victim);
     break;
     case 6:
message_vision(sprintf(HIY"$N�������ң������御��ʹ��"HIR"�����쳾"HIW"֮"HIB"����������"+NOR+""+HIY+"��������ŭ�ΰ�ӿ��$n��\n"NOR),me,victim);
     break;
     case 7:
message_vision(sprintf(HIY"$N������£��޺����ʹ��"HIR"�����쳾"HIW"֮"HIC"�������ϡ�"+NOR+""+HIY+"�������籯����ǣ��$n��\n"NOR),me,victim);
     break;
     case 8:
message_vision(sprintf(HIY"$N�������ͣ�ƽ�ľ�����ʹ��"HIR"�����쳾"HIW"֮"HIW"�����ĵ���"+NOR+""+HIY+"�����������ΰ�ֱȡ$n��\n"NOR),me,victim);
     break;
     }
     if( me->query_skill("dream-blade",1)> random(60)+100)
     {
message_vision(sprintf(MAG"�����$Nȷȷʵʵ������Ҫ����$n������������һ��������˺ۣ�\n"NOR),me,victim);
          victim->receive_wound("qi",90,me);

          COMBAT_D->report_status(victim,1);

     }
     else
     {
           message_vision(sprintf(HIB"���$N�Ĺ�����$n���˿�����\n"NOR),me,victim);
     }
   }
}


//��˼���ε����İ���������
void fast(object me,object victim,object weapon,int damage)
{
    int i;

    if( userp(me) && !me->query("yi/dream") ) return;
    if(( (int)me->query("force") > 300 ) && me->query("force_factor") && me->query("bellicosity") < 200  && damage>0)
    {
       message_vision(CYN"\n\n\t$NЦ��΢��������·����һ����Ӱ��һ˲����������һ��������\n\n"
                            HIW"\t����"BLINK""HIR"  ���ΰ��壮��������"NOR""HIW"  ����\n\n"NOR,me,victim);
       for(i=1;i<=3;i++)
       {
         switch(i)
         {
            case 1:
            message_vision(HIY"\n����"HIR"��   ��"HIY"����\n"NOR,me,victim);
            message_vision(HIW"�������磬�������Σ���ɫ�ͷף������ĵ��⣬��ͬ�������ŷ绪��\n�ռ�Ϊ�����������"
                                       +"��ʹ⻪�����������һ�����������ڿ������֣�\n��Ѥ��һ������һ��Ļ������\n"NOR,me,victim);
             break;

            case 2:
            message_vision(HIY"\n����"HIR"��   ��"HIY"����\n"NOR,me,victim);
            message_vision(HIW"�����Լ������һ����������������ɱ�⣬�������˷���������ɽ�����Ļ�����\n"+
                                         "����ɢ����������Ŀ�Ĺ�ʣ�Ѫ�Ƶ��ʺ�ɫ���������ң����Ѳ�ɫ���Ρ���\n"NOR,me,victim);
             break;

            case 3:
            message_vision(HIY"\n����"HIR"��   ��"HIY"����\n"NOR,me,victim);
            message_vision(HIW"���׺��𣬴�ظ������������һ������ǿ�⣬�Ѳ���������������������쭺���\n"+
                                        " �·�Ǳ���ص׵�ŭ�������ζ����������죬�������������ƥ����\n"NOR,me,victim);
             break;
           }
           if( me->query_skill("dream-blade",1) > random(60)+100)
           {
                  message_vision(MAG"\n$N�ĵ�����������ƻã�$n��������һ����ɼ��ǵ��˺�ȴ����֪��\n"NOR,me,victim);
                  victim->receive_wound("qi",400,me);
                  me->add("force",-50);
                  if(i != 3)
                  COMBAT_D->report_status(victim,1);
                  else if( damage <=0 )
                  COMBAT_D->report_status(victim,1);
           }
            else
            {
                  message_vision(HIB"$n������$N�Ĺ��ƣ����첻���ı��˿�����\n"NOR,me,victim);
            }
        }
    }
}




//������ֵ�enforce
void disenforce(object me, object victim, object weapon, int damage)
{
        int skillb = (int)me->query_skill("love-sword",1);
        int me_jing = me->query("max_jing")/5;
        int me_qi = me->query("max_qi")/10;
        int me_sen = me->query("max_sen")/5;
        int victimenf = victim->query("force_factor");
        if( !me->query_temp("disenforce"))
        {
          if(skillb >= 100 && me->query("bellicosity",1)<30 && damage>0 && victimenf > 0)
            {
                message_vision(HIR"\n
             $N�ĵ���������ƽ�����ޱ仯��ȴ��Ȼ�䣬��������һ�ֺ��������\n\n"
HIR"              ���Ʊ����ܿ죬������ʱ��Ȼ������������������Ȼ����ȴ�����ڱ�\n\n"
HIR"                        ��â���֣��������죬������ã����������\n\n"
HIR"                $n������ݹ���·�����Լ�ü�޼䣬�ַ·������޵���翼�\n\n"
NOR"            "HBBLU"���⽣��������$n��־��������$n�Ķ�־����$n����������˱�����\n"NOR, me, victim);
                me->set_temp("disenforce",1);
                victim->set("force_factor", 0);
                me->receive_wound("jing",me_jing,me);
                me->receive_wound("qi",me_qi,me);
                me->receive_wound("sen",me_sen,me);
            }else{ message_vision(NOR"\n"NOR,me,victim);}
        }
        else {me->delete_temp("disenforce");}
}
*/
int valid_learn(object me)
{
        int bell, skill;
        object ob;
        bell = me->query("bellicosity");
        skill =me->query_skill("love-sword", 1);
        if(me->query("get-2skill-s") != 1 )         //��love-sword��mark
        {
         tell_object(me, HIY"��Сʯ˵�������Ҽ���ʦͽ֮ʵ����ô���Ҵ��ڽ������㣡\n"NOR);
         return 0;
         }
         else
         {
         if( me->query("family/master_name") != "��Сʯ" )
         {
                tell_object(me, HIY"��Сʯ˵�������Ҽ���ʦͽ֮ʵ����ô���Ҵ��ڽ������㣡\n"NOR);
                return 0;
         }
         if((int)me->query("max_force") < 2000)
         {
                tell_object(me, HIY"��Сʯ˵�������������Ϊ�ƺ��������������齣����\n"NOR);
                return 0;
         }
         if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "sword" )
         {
                tell_object(me, HIY"��Сʯ˵����û�ý���ô����������\n"NOR);
                return 0;
         }
         if( (me->query("potential") - me->query("learned_points")) < 5 ) {
                tell_object(me, "���Ǳ�ܲ������, �޷����˽�����\n");
                return 0;
         }
         if( bell > 100 )
         {
                tell_object(me, HIY"��Сʯ˵�������Ĵ�ɱ��, ��ô�ܹ�ѧϰ�齣�أ�\n");
                return 0;
         }
        tell_object(me, HIY"��Сʯ˵����ѧ�˽������Ǳ�ܡ�����������㡣\n");
        me->add("jing", -5);
        me->add("qi", -5);
//        me->add("sen", -5);
        me->add("potential", -5);
        return 1;
       }
}
int valid_enable(string usage)
{
        return usage== "sword" || usage=="parry";
}
/*
string perform_action_file(string action)
{
        return CLASS_D("blademan")+"/love-sword/"+action;
}

string exert_action_file(string action)
{
        return CLASS_D("blademan")+"/love-sword/"+action;
}
*/