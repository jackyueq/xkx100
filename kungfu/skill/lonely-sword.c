// lonely-sword.c ���¾Ž�
// Last Modified by sir 10.22.2001

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h"

inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
int action_po(object me, object victim, object weapon, int damage);//
int action_busy(object me, object victim, object weapon, int damage);
int action_damage(object me, object victim, object weapon, int damage);//
int action_parry(object me, object victim, object weapon, int damage);
int action_dodge(object me, object victim, object weapon, int damage);


string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *parry_msg = ({
	"ȴ��$n̤ǰһ������ʽбָ����ұۣ���Ҫʹ$P������ˡ�\n",
	"$n�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����������$P�͹����ػӳ���λ�����̩ɽ"+(order[random(13)])+"���������"NOR"������\n",
	"$n����ͻ�䣬�����������������ڽ�ز����ʹ��ɽ������"+(order[random(13)])+"������������"NOR"��ͼ��ʹ$P���С�\n",
	"$nͻȻһ������$P��$l����һ��ȴ�����������ţ�$P�����޴룬���Ʋ�������ͣ��������\n",
	"$n�������ܣ��ٽ������ʹ��"+(order[random(13)])+"�����両�ࡹ"NOR"����$P��$l���뵲������С�\n",
	"$nͻȻʹ��������ɷ罣����"+(order[random(13)])+"�����ڤڤ��"NOR"�����Ƿ�λȴ����ƫ���������$Pһ�ʣ���\nͼͻ��$P�Ĺ��ƣ�\n",
	"$nͦ��һ������"+(order[random(13)])+"�����Ƴ�ᶡ�"NOR"�ش�$P��$l����ͼ��$P�Ĺ��ƻ��⡣\n",
	"ֻ��$n���˷���������Ʈ�磬�����һʽ"+(order[random(13)])+"������������"NOR"�������޶�����׽���ص�ס��$P��\n������\n",
	"$n���˷�����ʹ����ɽ����"+(order[random(13)])+"��������롹"NOR"��ɭɭ�����������ܣ��ܿ���$P������\n",
});

mapping *action = ({
([	"action" : "����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ������"+(order[random(13)])+"��������Ȫ��"NOR"ֱ��$n
��$l��",
	"lvl" : 0,
	"skill_name" : "������Ȫ"
]),
([	"action" : "$N������$n�ӳ�"+(order[random(13)])+"��Ȫ��ܽ�ء�"NOR"��"+(order[random(13)])+"�������ϸǡ�"NOR"��"+(order[random(13)])+"��ʯ��������"NOR"��"+(order[random(13)])+"��
����������"NOR"��"+(order[random(13)])+"�����ף�ڡ�"NOR"��ɽ���񽣣�",
	"lvl" : 10,
	"skill_name" : "��ɽ����"
]),
([
	"action" : "$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ"+(order[random(13)])+"����Ůʮ�Ž���"NOR"�������
����ʮ�Ž�����һ�У��ַ�֮�죬ֱ�Ƿ�����˼��",
	"lvl" : 20,
	"skill_name" : "��Ůʮ�Ž�"
]),
([	"action" : "$N���ƺ��������裬�������������������ɽ����Ϊһ������$n����
��ȥ��",
	"lvl" : 30,
	"skill_name" : "��ɽ����"
]),
([	"action" : "$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮����ʵ�����Ѳ⣡",
	"lvl" : 40,
	"skill_name" : "��֮��"
]),
([	"action" : "$N����������һ������"+(order[random(13)])+"��������ɽ��"NOR"������$w����ն�䣬ֱ����$n��
$l��",
	"lvl" : 50,
	"skill_name" : "������ɽ"
]),
([	"action" : "$N��Ц����������ׯ�ϣ�$w��ӣ�����"+(order[random(13)])+"����Ħ����"NOR"Ϊһʽ������ش�
��$n��",
	"lvl" : 60,
	"skill_name" : "��Ħ��"
]),
([	"action" : "$N�������أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n��"+(order[random(13)])+"����Ħ
����"NOR"�Ľ����¶���ţ�",
	"lvl" : 70,
	"skill_name" : "��Ħ��"
]),
([	"action" : "ȴ��$NͻȻ�鲽������ʹ�������䵱"+(order[random(13)])+"�����ѵ�ˮ��"NOR"��һ�У�",
	"lvl" : 80,
	"skill_name" : "���ѵ�ˮ"
]),
([	"action" : "$N�˽���磬��������з���$n��$l�����Ա�$n���أ���������"+(order[random(13)])+"����
ħ����"NOR"��"+(order[random(13)])+"������ʽ��"NOR"��",
	"lvl" : 90,
	"skill_name" : "����ʽ"
]),
([	"action" : "$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲ
ô������",
	"lvl" : 100,
	"post_action" : (: action_busy :),
	"skill_name" : "��������"
]),
([	"action" : "$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ���������
��$n���ò��أ�",
	"lvl" : 110,
	"post_action" : (: action_parry :),
	"skill_name" : "�󿪴���"
]),
([	"action" : "$N���ֺὣ����$n��$l���������������е�һ����������Ȼ���$n
���Կ��彣�����ƣ�",
	"lvl" : 120,
	"post_action" : (: action_dodge :),
	"skill_name" : "����������"
]),
([	"action" : "$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô��
ʽ��",
	"lvl" : 130,
	"post_action" : (: action_busy :),
	"skill_name" : "�ٽ����"
]),
([	"action" : "$NͻȻ�˽����һ�ֹ����"+(order[random(13)])+"�������罣����"NOR"����Ȼ��$n�����Ҵ���
����",
	"post_action" : (: action_damage :),
	"lvl" : 140,
	"skill_name" : "�����罣��"
]),
([	"action" : "$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N������
��ʵ��",
	"lvl" : 150,
	"post_action" : (: action_dodge :),
	"skill_name" : "Ī������"
]),
([	"action" : "ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�������
��"+(order[random(13)])+"��̩ɽʮ���̡�"NOR"Ϊһ������$n��",
	"lvl" : 160,
	"post_action" : (: action_damage :),
	"skill_name" : "̩ɽʮ����"
]),
([	"action" : "$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪
����Ǻã�",
	"post_action" : (: action_busy :),
	"lvl" : 170,
	"skill_name" : "��������"
]),
([	"action" : "$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n
��$l��",
	"post_action" : (: action_parry :),
	"lvl" : 180,
	"skill_name" : "ͻ��Ц��"
]),
([	"action" : "$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ��"+(order[random(13)])+"���ٱ�ǧ������ʮ��ʽ��"NOR"����
ʽ�����ƾ���ӿ���Թ��߲��ɵ�ĿΪ֮ѣ��",
	"lvl" : 190,
	"post_action" : (: action_dodge :),
	"skill_name" : "�ٱ�ǧ������ʮ��ʽ"
]),
([	"action" : "$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ��
��������ɽ���ƻ���$n��$l��",
	"lvl" : 200,
	"post_action" : (: action_damage :),
	"skill_name" : "��ǹ���"
]),
([	"action" : "$N����$w��ʹ"+(order[random(13)])+"��̫������"NOR"���⣬�������СС������ԲȦ�������޾�
ԴԴ�����ز���$n��",
	"post_action" : (: action_busy :),
	"lvl" : 210,
	"skill_name" : "̫����"
]),
([	"action" : "$N����ͻ�䣬ʹ����ɽ��"+(order[random(13)])+"��һ������㡹"NOR"������$n��$l����֪������
;��ͻȻת�򣬴��$n����֮�⣡",
	"lvl" : 220,
	"post_action" : (: action_parry :),
	"skill_name" : "һ�������"
]),
([	"action" : "$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����
˼�飡",
	"post_action" : (: action_po :),
	"lvl" : 230,
	"skill_name" : "��������"
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}
int valid_learn(object me)
{
	object ob;

	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "��ɽ��"|| myfam["master_id"] != "feng qingyang")
		return notify_fail("���¾Ž�ֻ�����������ǰ��ѧϰ��\n");
	if( (int)me->query("max_neili") < 600 )
		return notify_fail("�������������û�а취�����¾Ž���\n");
	if( (int)me->query_skill("zixia-shengong",1)<100)
		return notify_fail("���¾Ž����������ϼ�񹦲�����ϰ��\n");
	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");
	if ((int)me->query_skill("lonely-sword",1) > 120)
		return notify_fail("���׽����Ҿͽ̵�������Ժ��Ҫ�����Լ����ˡ�\n");

	return 1;
}
int practice_skill(object me)
{
	return notify_fail("���¾Ž�ֻ��ͨ�����ܾ�ʽ����������\n");
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -25;
	int d_e2 = -5;
	int p_e1 = -55;
	int p_e2 = -35;
//	int f_e1 = 150;
//	int f_e2 = 230;
//	int m_e1 = 220;
//	int m_e2 = 320;
	int f_e1 = 230;
	int f_e2 = 150;
	int m_e1 = 320;
	int m_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("lonely-sword", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* �������������� */
			break;
		}
	seq = random(seq);       /* ѡ������������ */
	if (!userp(me) || me->query("family/master_id")== "feng qingyang" )
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"post_action" : action[seq]["post_action"],
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "����" : "����",
	]);
  else	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
//		"post_action" : action[seq]["post_action"],
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "����" : "����",
	]);
}


int action_damage(object me, object victim, object weapon, int damage)
{
       	string msg;
        string *limbs=victim->query("limbs");
        int dam;
        int skill= me->query_skill("lonely-sword", 1);
        if (!me->is_fighting(victim)) return 0;
	      if( damage == RESULT_DODGE && !victim->is_busy()
	            && skill > 100
	            && me->query("neili") > 100
	            && random(skill) > victim->query_skill("force",1)/2 ) //���
        {
        	me->add("neili",-50);
        	message_combatd("\n$Nһ����Х:"HIW"������������Х��ɽ�ӡ�"NOR", ˲�佣â����,��$n���������\n",me,victim);
          dam = skill*2 + me->query_temp("apply/damage");
          dam -= victim->query_temp("apply/armor");
          if (dam < 0 ) dam = 0;
          victim->receive_damage("qi",dam);
          msg = damage_msg(dam, "����"); //�˴��˺�
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
          return 1;
        }
        else if (  damage > 0 && !victim->is_busy()
	            && skill > 100
	            && me->query("neili") > 100
	            && random(skill) > victim->query_skill("force",1)/4)   //���жԷ�
        {
        	me->add("neili",-50);
          message_combatd("\n$NͻȻ���"HIW"����������, ��������, �����项"NOR"֮����, ���г���ͻȻ��ʧ, ��$n������\n",me,victim);
          dam = skill + me->query_temp("apply/damage");
          dam -= victim->query_temp("apply/armor");
          if (dam < 0 ) dam = 0;
          victim->receive_damage("qi",dam);
          msg = damage_msg(skill*2, "����"); //�˴��˺�
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
        	return 1;
        }
        return 1;

}

int action_po(object me, object victim, object weapon, int damage)
{
	// �ƶԷ��书���ڹ�  Ϊ�ռ�Ч��
	      int skill= me->query_skill("lonely-sword", 1);
        string v_force = victim->query_skill_mapped("force");
        int jiali;
        if (!me->is_fighting(victim)) return 0;
	      if (damage > 0)// ���жԷ� ���ڹ� ����������
	      {
	      	if (v_force && skill > 250 
	      	   && random(skill/2) > random(victim->query_skill("force"))  
	      	   && random(skill) > 200 
	      	   && victim->query_map_skill("force") 
	      	   && random(3)==1 )
	      	{
	      		me->add("neili",-100);
	      		victim->map_skill("force");
            message_combatd(HIC "$Nһ�����֣�����ԴԴ����������ֱ��$n���\n",me,victim);
            message_combatd(RED "$nֻ���������������������������ѿأ���Ȼ����ʩչ"+to_chinese(v_force)+"��\n" NOR,me,victim);
	        return 1;
	        }
	        else if (random(me->query_skill("lonely-sword",1)) > 100 &&
          random(me->query_skill("sword",1))>100 &&
         	me->query_skill("force",1) > 120
      	  && !victim->is_busy() )	
          {
          	me->add("neili",-50);
            if (victim->query("neili")>600)
               victim->add("neili", -500);
            else
               victim->set("neili",0);
          message_combatd(HIC "\n$Nһ�����֣�����ԴԴ����������$n������ס��\n",me,victim);
          message_combatd(HIM "$n����������ʹ����������������ѳ���Ȧ��\n"NOR , me, victim);
          return 1;
          }        
	      }
        else if( damage == RESULT_DODGE && !victim->is_busy()) //���  ����Է�
        {
        	me->add("neili",-50);
        	message_combatd(HIY "$nֻ��$N���а���������������һ���ӣ����ҹ���ǰȥ��\n"NOR,me,victim);
          victim->start_busy(1+random(skill/50));
        	return 1;
        }
        else if ( damage == RESULT_PARRY ) //�����м�ס ��˳���ٴ�����
        {
        	jiali = me->query("jiali");
          if (!jiali) jiali=10;
	        if( random(skill)>140 )
	        {
	        	me->add("neili",-50);
            message_combatd(HIC "$N�ཻһ�У���Ȼ����$n�书��·�����г���ش̳�һ��!\n",me,victim);
	          victim->receive_wound("qi", (random(jiali)*2+100));
	          message_combatd(HIM"$N�����ݺ�! һ������������$n���ؿڡ������Ѫ����!\n"NOR,me,victim);
            COMBAT_D->report_status(victim,1);
           }
        	return 1;
        }
        return 1;
	
}
int action_busy(object me, object victim, object weapon, int damage)
{
	      int skill=me->query_skill("lonely-sword",1);
        if (!me->is_fighting(victim)) return 0;
        if( damage <= 0 && !victim->is_busy() 
            && skill > 100
            && me->query("neili") > 100
            && random(me->query("combat_exp")) > victim->query("combat_exp")/3 ) //������С,���û�������� �����������м�
        {
         me->add("neili",-50);
         message_combatd("$N��Ȼ������"HIW"����������, ���಻����"NOR"֮����, ����˲�䱬���������СС,\n����бֱ���ָ�����ԲȦ, ��$n������ס��\n",me,victim);
         victim->start_busy(2+random(skill/50));
       	return 1;
        }
	      else if (damage > 0  && !victim->is_busy() 
          && skill > 100
	        && random(skill) > victim->query_skill("force",1)/3)
	      {
	      	  me->add("neili",-30);
	         	message_combatd(CYN"$N����Ԧ������������"RED"ԲȦ"CYN"�����Ҽ�ˣ���$n�������У�\n" NOR,me,victim);
		        victim->start_busy(1+random(skill/50));
	      }
	      return 1;
}

int action_dodge(object me, object victim, object weapon, int damage)
{
	      int skill=me->query_skill("lonely-sword",1);
	      string msg;
        string *limbs=victim->query("limbs");
        if (!me->is_fighting(victim)) return 0;
        if (random(me->query_skill("lonely-sword",1)) >= 200 &&
            random(me->query_skill("sword",1))>180 &&
          	me->query_skill("force",1) >= 200 &&
          	victim->query_map_skill("dodge")
           	)
       {
          me->add("neili", -50);
          victim->map_skill("dodge");
         if( !victim->is_busy() )
         {
           victim->start_busy(random(3)+1);
         }
         msg = HIC "\n$NͻȻ�ٽ�һ�̣�����������£�ȴĪ�������ͻ����$n�Ĺ��ƣ����$n���ϣ�\n" ;
         msg += HIR"$n���һ������Ȼ�������ܣ�\n"NOR;
         message_combatd(msg,me,victim);
         return 1;
       }
	     else if (damage <= 0 && random(skill) > random(victim->query_skill("dodge",1)/3))
       {          
          me->add("neili", -50);
  	      message_combatd("\nȴ��$NƮ����ϣ�����оٽ������������ѷ�ס��$n��������֮�أ����þ����ޱȣ�\n",me,victim);
  	      victim->receive_damage("qi",skill/2);
          msg = damage_msg(skill/2, "����");
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
          return 1;
       }
       return 1;
}

int action_parry(object me, object victim, object weapon, int damage)
{
	     int skill=me->query_skill("lonely-sword",1);
       string msg;
       string *limbs=victim->query("limbs");
        if (!me->is_fighting(victim)) return 0;
       if (damage == RESULT_DODGE &&
           random(me->query_skill("lonely-sword",1)) > 140 &&	
	         random(me->query_skill("sword",1))>140 &&
           me->query_skill("force",1) >= 200 &&
          	victim->query_map_skill("parry")
           )	
         {
           me->add("neili", -50);
           victim->map_skill("parry");
           if( !victim->is_busy() )
           {
             victim->start_busy(random(2)+1);
           }
           msg = HIC "\n$N�ٽ��������������ش���$n��������$n��������������һ������������\n" NOR;
           msg += HIY"$n���Կ��彣������,��Ȼ�����мܣ�\n"NOR;
           message_combatd(msg,me,victim);
        }
	      else if (damage <= 0 && random(skill) > random(victim->query_skill("parry",1)/3))
       {
          me->add("neili", -50);
        	msg = "\n$Nһ�������ݵ�$n��ǰ������΢�����ӽ�б�ã�����$n$l�����������鶯���\n";
  	      victim->receive_damage("qi",skill/2);
          msg += damage_msg(skill/2, "����"); //�˴��˺�
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
       }
}
//������Ч��
mixed be_hit_ob(object me, object ob, int damage, int factor)
{
		   object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        if ((int)me->query("qi")>1 && (int)me->query("eff_qi")>1)
            i = (int)me->query("eff_qi") / (int)me->query("qi") + 1;
        else i=1;
        if ( i > 5 ) i = 5;
        limbs = ob->query("limbs");
        level = me->query_skill("lonely-sword", 1);

//        if( me->is_busy()) return 0;
        if( damage < 100 ) return 0;
        if ( living(me) 
         && !me->query_temp("noliving")
         && random(level) > 100 /i 
         && me->query_skill_mapped("sword") =="lonely-sword"
         && me->query_skill_mapped("parry") =="lonely-sword"
         && weapon
         && weapon->query("skill_type") == "sword"
         && me->query_skill("sword") > 300
         && random(me->query_skill("sword",1)) > 150
         && me->query("neili") > 200 
         && me->query("max_neili") >= 3000
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIW"$N�ж����㣬֪����һ���޿ɶ�ܣ�����ͦ���̳������������۵�һ������$n���ʺ�\n"NOR;
            if ( random(level) > ob->query_skill("dodge", 1) / i){
             q = damage * i ;
             if ( q > 3500 ) q = 3500 + ( q - 3500 )/ 100;
             ob->receive_damage("qi", q);
             ob->receive_wound("qi", q/3);
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
     //        if ( random(me->query("combat_exp")) > ob->query("combat_exp") / i)
             p = ob->query("qi")*100/ob->query("max_qi");
             msg += damage_msg(q, "����") + "( $n"+status_msg(p)+" )\n";
             msg = replace_string(msg, "$l", "����");
             msg = replace_string(msg, "$w", weapon->query("name"));
           //  j = -(damage/2+random(damage/2));
             j = 0;
            }
            else {
              dodge_skill = ob->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              msg += SKILL_D(dodge_skill)->query_dodge_msg(ob);
              j = -damage/4; 
            }
            message_combatd(msg, me, ob);
            return j;
        }
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
	return __DIR__"lonely-sword/" + action;
}

int help(object me)
{
	write(HIC"\n���¾Ž���"NOR"\n");
	write(@HELP

    �����¾Ž����н����ˣ���
    �������׽����Ķ������ǰ�������ֽ�������ܡ�����������
��һ�ܶ����ɵã��⽣��ʩչ�����������޵У��������̽�������
�޵������£�����һ���������Ƶ�������һ�ж����ɵã�ίʵ����
�ɾ����塣
    ����ʤ���У���ǿ�Ҹ�ǿ�����¾Ž�������ʽ�����м����У�
���������С����¾Ž�Ҫּ���ڡ��򡹣����ɾ��಻���������ϵ�
���ȣ�������ʤ��ͨ���˾Ž����⣬������ʩ�����ɡ�
    ���¾Ž����ԡ��ܾ�ʽ�������ƽ�ʽ�������Ƶ�ʽ����������
ǹʽ�������Ʊ�ʽ����������ʽ����������ʽ�������Ƽ�ʽ������
�ھŽ�������ʽ�����Ž��ĵ�һ�С��ܾ�ʽ���������ֱ仯������
�����ܾ���������ϰ���ڶ��С��ƽ�ʽ���������ƽ������¸��Ÿ�
�ɵĽ����������С��Ƶ�ʽ���������ƽⵥ����˫������Ҷ������
ͷ�����󿳵���ն�����ֵ����������С���ǹʽ���������ƽⳤ
ǹ����ꪡ���ì����ü�����������������ˡ����ȡ���������ֳ�
����֮���������С��Ʊ�ʽ���������ƽ�ֱޡ���ﵡ���Ѩ�ӡ���
�ӡ���ü�̡�ذ�ס��師�����ơ��˽�鳡���׵�ȵȶ̱��У�����
�С�����ʽ�����ƽ���ǳ�������ޡ����ڹ�������ǹ����������
�����ɴ����ǵȵ�����С������С�����ʽ�����Ƶ���ȭ��ָ����
�Ĺ��򣬽���ȭ�̴����õ�Ѩ��ħצ��צ����ɳ���ƣ����ȭ��
�������������ڡ��ڰ��С��Ƽ�ʽ������������֣����������
����������һ��ʱ�������ѧ�������֮��������Ҫ����һ������
�������˷����������ְ�����������������Ե��������İ�����
���˵С��ھŽ�������ʽ������Ϊ�Ը�����ϳ��ڹ��ĵ��˶��ã�
�����֮�����һ�ġ�

	ѧϰҪ��
		ֻ���������ѧϰ
		��ϼ��100��
		����600
HELP
	);
	return 1;
}

