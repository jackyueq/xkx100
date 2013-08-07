// /clone/medicine/nostrum/binghuojiu.c �����̻��
// Modified by Zeratul Jan 11 2001 force>�����ڹ�ʱ�Ⱦ�������������֮������

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_drink", "drink");
        add_action("do_drink", "he");
}
void create()
{
	set_name(HIC "�����̻��" NOR, ({"xuanbingbihuo jiu", "jiu"}));
	set("unit", "��");
	set("long", "����һ�����֮���������̻��, ��˵��������Ϊ�м������档\n");
	setup();
}
int do_drink(string arg)
{
	object me = this_player();
	mapping	skill_map = me->query_skill_map();
	int force_limit = me->query_skill( "force" ) * 10;
	int neili_limit = me->query( "max_neili" );
	
        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(arg=="jiu")
        {
        	tell_object( me, HIM"������ͷ���������еľƾ����ȸɣ���ʱ��ʹ��ʡ���������������\n" 
        		+ "Ҫ���������ź���֮�ﻯȥ����֪��ƵĶ��Է�ͬС�ɣ���һ����\n"
        		+ "������ֻʹ����ȫ��鴤�����㾷�Σ���ʱ������ȥ��\n"NOR );
        	if ( me->query_skill( "force", 1 ) < me->query_skill( skill_map["force"], 1 ) )
        	{
        		me->apply_condition( "scorpion_poison", 20 );
			me->apply_condition( "snake_poison", 20 );
			me->apply_condition( "flower_poison", 20 );
			me->add( "max_neili", -random(50) );
			tell_object( me, HIR"��ֵ���ס���ҵ�ҩ�ԣ���ʱ������ȥ��\n"NOR );	
			me->unconcious();
		}
		else
		{
			tell_object( me, HIG"�㽫��ǰѧ��������������书ʩչ�������Ҵ����ġ�ֻ��ÿ����\n"
				+ "һȭһ�ƣ����е���ʹ�������������߶�����һЩ������ʹ��һ��\n"
				+ "ȭ�ţ�������ʹҲ��֮������ֱ���綾��������Ǹ���Ҳ�Ͳ�����\n"
				+ "ʹ��������Ϊ�ƺ����˲�С���档\n" );
			if ( neili_limit < force_limit )
				me->add( "max_neili", 50 + random(100) );
		}
             	destruct(this_object());
        }
        return 1;
}
