
//���ֻ��ȡ�lunhui-zhang.c
//2001 by lestat

inherit SKILL;
#include <ansi.h>;
string* skill_head =({
        "$N������ţ���ɫׯ�ϣ�һ��",
        "$N�Ϻ�һ����ʹ��һʽ",
        "$N����һ��",
        "$N����һ�ݣ�һʽ",
        "$N��������һ��",
        "$N��¶ϼ�⣬ʹ��һ��",
});
string* skill_tail =({
        "������$w����ֱ�룬�ɴ�$n$l",
        "������$w�������ֵ�����$n",
        "��ֱ��$n",
        "������$w����ǧ�ֱ��$w��",
        "������һ�ݣ�����$wֱ��$n��$l",
        "��$n��ʱ��æ���ң�$w��Ҫ�䵽$l��",
});

mapping *action = ({
        ([      "name":                 "��Ӧ��ˬ",
                "action":
"$N������ţ���ɫׯ�ϣ�һ��"+BLINK""+HIR"����Ӧ��ˬ��"NOR"����$w����ֱ�룬�ɴ�$n$l",
                "dodge":                -10,
     "parry":               -5,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���޽���",
                "action":
"$N����$wһ����ʹ��"+BLINK""+HIB"�����޽�����"NOR"������һ����Ӱ����ԼԼ���������޵���$nѹ��",
                "dodge":                15,
      "parry":               -15,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ͷ�ǰ�",
                "action":
"ֻ��$N����$w���ᣬ���ص��������"+BLINK""+HIM"����ͷ�ǰ���"NOR"����Ʈ�ݣ�\n$n�ۼ��ȷ�Ϯ��������֪����Ǻ�",
                "dodge":                20,
     "parry":               -20,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�ڽ�����",
                "action":
"$N���һ��������$w��$n��ͷ���䣬����δ�����ѽ�$n������·��������һ��"+BLINK""+HIC"���ڽ����ӡ�"NOR"",
                "dodge":                -5,
     "parry":               0,
                "damage":               50,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�����ֻ�",
                "action":
"$N����$w������һ�ݣ�һ��"+BLINK""+HIW"�������ֻ֡�"NOR"��$n���벻���ĵط��̳���$n��ʱ�����޴룬�Ǳ����",
                "dodge":                -10,
     "parry":               -5,
                "damage":               35,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�ٶ��ֻ�",
                "action":
"$N����ͻ��ɷ������������$w������$n$l���䣬����"+BLINK""+RED"���ٶ��ֻء�"NOR"�����ֿ��ֺ�",
                "dodge":                20,
     "parry":               -15,
                "damage":               55,
                "damage_type":  "����"
        ]), 
        ([      "name":   "�ɽ�",
    "action" : HIW"\n$NĬ����ţ����е�$w��һ�㵭���İ���ֱֱ����$n����ǰ�����һ���������ɽ١���"NOR,
    "dodge" : -15,
    "damage" : 40,
    "force"  : 100,
    "parry"  :-120,
    "lvl" : 0,
    "damage_type" : "����"
	]),
	([      "name":   "����",
    "action" : HIW"\n$N����$wһ�񣬰�ɫ������Ȼ����ȫ������֮��������ڶ�ʽ�����ѡ���Ȼ�ĳ���"NOR,
    "dodge" : -15,
    "damage" : 50,
    "parry"  :-100,
    "force"  : 120,
    "lvl" : 0,
    "damage_type" : "����"
	]),
	([      "name":   "�ɶ�",
    "action" : HIW"\n$N������$w������˷�ľ�������ӿ������\n���ɶ�һʽ֮�����Լ���Ҷ���Ҳ������ʨ�Ӻ𡱣�"NOR,
    "dodge" : -10,
    "damage" : 60,
    "parry"  :-100,
    "force"  : 120,
    "lvl" : 0,
    "damage_type" : "����"
	]),
	([      "name":   "�ȹ��ն�",
    "action" : HIC"\n$N������������ͷ�ǰ����������߳߾���ӿ����\n�����ӷ������������Ϲ����ջ������ȹ��նɡ����ȶ�����"NOR,
    "dodge" : -10,
    "damage" : 80,
    "parry"  :-120,
    "force"  : 120,
    "lvl" : 0,
    "damage_type" : "����"
	]),  
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("�������������û�а취ѧ�ֻ��ȣ�����������������ɡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "staff" )
                return
notify_fail("���������һ�����Ȳ���ѧ�ֻ��ȡ�\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
     int i;
	i=me->query("ciguangpudu");
	if( !me->query("ciguangpudu") ) {
     mapping* m_actions;
     m_actions=me->query("skill_lunhui-zhang");
     if(me->query("skill_lunhui-zhang")==0 )
     return action[random(6)];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
    	
        return action[random(6)];
	}else {
	return action[i];
	}
     
     
}


int practice_skill(object me)
{
        if( (int)me->query("kee") < 20
        ||      (int)me->query("force") < 5 )
                return
notify_fail("�����������������û�а취��ϰ�ֻ��ȡ�\n");
        me->receive_damage("kee", 20);
        me->add("force", -5);
        write("�㰴����ѧ����һ���ֻ��ȡ�\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("bonze") + "/lunhui-zhang/" + func;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("lunhui-zhang",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"����ֻ��ȵ���������ˣ�����ֻ��Ƚ�����һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬���ֻ����������һ���µ��÷���\n"NOR);
    tell_object(me,"��Ϊ����ȡһ�����֣�");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_lunhui-zhang");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   if(!arg||arg==" ")arg="�ֻ��ȱ�ɱ��"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIY"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_lunhui-zhang",m_actions);
}
