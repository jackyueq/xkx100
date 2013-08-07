// zhui.c 
#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name(HIC"��׶"NOR, ({ "tie zhui", "zhui" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("count", 12);
                set("value", 100);
                set("material", "iron");
                set("long", HIC"����׶�����ߴ���׶���������������湲��"+chinese_number(query("count"))+"֧��䶤�������(shoot)��\n"NOR);
                set("wield_msg", HIC"$N�����������������䣬�漴�������������������һ����׶��\n"NOR);
                set("unwield_msg",HIC"$N��������׶������һ���Ͳ����ˡ�\n"NOR);
        }
        init_dagger(5);
        setup();
}

void init()
{
	add_action("do_shoot","shoot");
}

int do_shoot(string arg)
{
	object weapon, obj, me = this_player();
	int attacklvl, dodgelvl, parrylvl, damage;

	if (environment(this_object())!=me)
		return 0;
	if(environment(me)->query("no_fight"))
		return notify_fail("�����ֹս����\n");
	if( (me->is_busy() ))
		return notify_fail("��������æ���أ�û�����á���䶤����\n");
	if( !arg )
		return notify_fail("��Ҫ���˭��\n");
	if( !objectp(obj = present(arg, environment(me)) ))
		return notify_fail("����û������ˣ�\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	if( !me->is_fighting(obj) )
		return notify_fail("����䶤��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( obj == me ) return notify_fail("���Լ������벻������\n");
//	obj = me->select_opponent();

	if( query("count") == 0 )
		return notify_fail("��䶤������ˣ����ְա�\n");
	attacklvl = me->query_skill("qingzi9da", 1);
	parrylvl = obj->query_skill("parry", 1);
	dodgelvl = obj->query_skill("dodge", 1);
	damage = obj->query("eff_qi");
	if( me->query("neili") < 400 )
		return notify_fail("����������㣬����������䶤��\n");
	if( me->query_skill("qingming-xuangong", 1) < 30 )
		return notify_fail("�����ڤ������򲻵����޷�������䶤��\n");
	if( attacklvl < 10 )
		return notify_fail("������־Ŵ��򲻵����޷�������䶤��\n");

	add("count", -1);
	me->add("neili", -300);
	weapon = new(__DIR__"qingfengding");
/* ���� */
	if( attacklvl < 40 )
	{
		message_vision(HIG"$N����׶��һ�ã�һ֧��䶤���������\n"NOR, me);
	}
	else
		if( attacklvl < 70 )
		{
			message_vision(HIG"$N����׶��һ�ã�һ֧��䶤��Х������\n"NOR, me);
		}
		else
			if( attacklvl < 100 )
			{
				message_vision(HIG"$N����׶��һ�ã�һ֧��䶤�ƿ������\n"NOR, me);
			}
			else
			{
				message_vision(HIG"$N����׶��һ�ã�һ֧��䶤���������\n"NOR, me);
			}

	if(userp(obj)) obj->kill_ob(me);
	else obj->fight_ob(me);

	me->start_busy(2);
/* ���� */

	if( attacklvl < (int)(dodgelvl/2) + random((int)(dodgelvl/2)) )
	{
		weapon->move(obj);
		message_vision(HIY"$N��Цһ���������Ѿ��ֻһ�У����ɵ�ס����䶤��\n"NOR, obj);
		return 1;
	}
//	if( attacklvl < (int)(dodgelvl/2) + random(parrylvl))
	if( attacklvl < random(dodgelvl) + random(parrylvl))
	{
		weapon->move(environment(me));
		message_vision(HIY"$Nһ����ߣ�̧����ʳָһ�������õ�����䶤�ϣ���䶤һ����أ�\n"NOR, obj);
		return 1;
	}
	if( attacklvl < (int)(parrylvl/2) + random((int)(parrylvl/2)) )
	{
		weapon->move(obj);
		message_vision(HIY"$N���¶��һ˿��Ц��һ̧�ֱ㽫��䶤�����������\n"NOR, obj);
		return 1;
	}
	if( attacklvl < dodgelvl )
	{
		message_vision(HIY"$N������һת���ܿ�����䶤��\n"NOR, obj);
		return 1;
	}
	if( attacklvl < parrylvl )
	{
		weapon->move(obj);
		message_vision("$N����������һ���죬��Ȼҧס����䶤��\n"NOR, obj);
		return 1;
	}

/* ���� */

	if( attacklvl > parrylvl + dodgelvl + random((parrylvl + dodgelvl) * 2))
	{
		message_vision(HIR"$Nһ����һ���ƺߣ���ͷ��Ȼ����һ֧��䶤��\n"NOR, obj);
		obj->die();
	}
	else
	if( attacklvl > parrylvl + dodgelvl + random(parrylvl + dodgelvl) )
	{
		message_vision(HIR"$Nһ������������һ���Һ�����䶤������$N�����ţ�\n"NOR, obj);
		obj->unconcious();
	}
	else
	if( attacklvl > random(parrylvl + dodgelvl) )
	{
		message_vision(RED"$Nһ������������һ���Һ�����䶤������$N���ؿڣ�\n"NOR, obj);
		if(damage < 11) obj->unconcious();
		else obj->receive_wound("qi", damage-10);
		obj->start_busy(3);
	}
	else
	if( attacklvl > parrylvl )
	{
		message_vision(HIM"$Nһ�����ӷ��������䶤����һ����������$N�Ĵ����ϣ�\n"NOR, obj);
		obj->receive_wound("qi", (int)(damage/2));
		obj->start_busy(3);
	}
	else
	if( attacklvl > dodgelvl )
	{
		message_vision(MAG"$N������������䶤����һ������$N�ĸ첲�ϣ�\n"NOR, obj);
		obj->receive_wound("qi", (int)(damage/3));
		obj->start_busy(3);
	}
	else
	{
		message_vision(HIW"$N����һԾ������䶤��$N���ֱ��ϻ�����һ���˿ڣ�\n"NOR, obj);
		obj->receive_wound("qi", (int)(damage/10));
		obj->start_busy(1);
	}
	return 1;
}

