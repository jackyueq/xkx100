// kuihua-shengong.c

#include <ansi.h>
inherit FORCE;

string *parry_msg = ({
"$n��һ������һ������һ������һ������$N���������������������²����������ް��������\n",
"$n���ִ�Ĵָ��ʳָ��סһ���廨�룬����һ�٣���ס���ƣ�$N����ʽ��ʹ����ȥ��\n",
"$n��������������ʳָ��������$N����Ŀ���̣��������ܾ��˵Ĵ򷨡�\n",
"$n���ҵ���أ�Ժ�����Ͼ��������$N���ޣ����ù��򣬺ù��򣡡�\n",
"$n�ӻ���ȡ��һ��ѩ�׵ĳ���������Ĩ��Ĩ������ֱ������Ϸ̨�ϵĻ�����$Nһ������ͣס���Լ�����ʽ��\n"
});

string  *msg = ({
"$N����һ�䣬��������۵�$n��ǰ����಻��һ�ߣ�����$w�Ѿ��̵�$n��$l",
"������Ӱ������$N���е�$w��$n��$lֱ�����������籼�ף��ܲ��ɱ�",
"$N������ϣ�������$n�ļ���һ���ٺ�ɳ�ȥ�������е�$wȴָ��$n��$l",
"$NͻȻԾ�����࣬$nһ̧ͷ�����ֿ��в���$N����Ӱ����һ�ɺ���ȴ�Ӻ�Ϯ��",
"$N��һ������һ������һ������һ������$n��������������������һת������$n",
"�����$N���������ϣ�˫�����õ��ģ���������֮������$n����֮�ʵ���$w����$n",
"$N����Ʈ����������ȣ�ת�˼�ת���Ʋ�������һ������$n������֮��֮�죬ֱ�Ƿ�����˼",
"$N����һ�٣�վ��Ƭ�̣�����$n����󷽻������࣬���ſ������׵Ļص�ԭ��",
"$NǱ���������������ˣ�����$n������ת������$w��ʹ����Ҳ��������һ�㣬Խ��Խ��",
"ͻȻ$N����$w����һ�ã�����$n΢һ����֮��ֱȡ$n��$l���Ƶ���������"NOR,
"����$nһ��֮�ʣ�$N����Ծ�����ߣ���������أ����Ӹ�������ˢˢ��������$n��ȥ",
"$N��Ȼ����Ϊ�����ֳ�����������Ӱ���ٻ���$n������$w�û�������ֱ��$n��$l",
"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪",
"$Nһ����У����������ڰ����һת������ޱȵķ�������������$w�ƿ�ֱ��$n$l",
"$N��Ȼ����Ϊ�����ֳ�����������Ӱ���ٻ���$n������$w���Ī�⣬ֱ��$n��$l",
"$N������������ȣ�Ʈ����ȥ��ֱ�����̣����е�$wȴ���Ƕ���$n����",
"$Nһ����Ц������Ｒ����ǰ�������Ƕ������ã�һ˲֮�䣬��$n����Ѳ���һ�ߣ����˵ı��Ӽ���Ҫ����һ��",
"$N�����������$n������Ѹ���ޱȵ�һ���������ֱۻ�ת������$n������һ��",
"$Nһ��ͦ�̣��������ţ���̬֮�У������л�ɽ��Ů������ѧ����Ů��ʮ��ʽ���ķ��ˣ�ֻ�Ǵ���������ɭɭ��а��",
"$N����һȦ����ת$w����ش̳���ˢˢˢ������ʽ�����о���ָ��$n��Ҫ��"
});

int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "force" || usage =="parry"; 
}
mapping query_action(object me, object weapon)
{               
       return ([
          "action":msg[random(sizeof(msg))],
          "damage":(random(4)+1)*60,
          "damage_type": "����",
          "dodge": random(30)+10,
          "force":(random(200)+60),
       ]);
}
string query_parry_msg()
{
        return parry_msg[random(sizeof(parry_msg))];
}
int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "sword")
               return notify_fail("��ʹ�õ��������ԡ�\n");
       if ((int)me->query_skill("kuihua-shengong", 1) < 180)
               return notify_fail("�㻹û���������񹦵ľ��裬����������ϰ��\n");
       if ((int)me->query("qi") < 30)
               return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("������������ˡ�\n");
       me->receive_damage("qi", 50);
       me->add("neili", -20);
       return 1;
}

int valid_learn(object me)
{
        if ((int)me->query_skill("kuihua-shengong", 1) < 180)
        return notify_fail("������ֻ��ͨ����ϰ���������䡷��ѧϰ��\n"); 
}

string perform_action_file(string action)
{
        return __DIR__"kuihua-shengong/" + action;
}

string exert_function_file(string func)
{
       return __DIR__"kuihua-shengong/" + func;
}
