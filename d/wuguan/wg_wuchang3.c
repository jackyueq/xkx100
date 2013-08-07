// Last Modified by Sir on 9/17/2001
// wg_wuchang3.c

#include <ansi.h>
inherit ROOM;
int do_chuo(string arg);
int do_ti(string arg);
int do_pai(string arg);
int do_zhua(string arg);

void create()
{
	set("short", "�����䳡");
	set("long", @LONG
���Ǽ���ķ��ӣ�ʮ�ֿ����������������ﺹ��䤱��Ŀ����Ź�
�򣬵�����һЩ�����õĹ��ߣ�ǽ�ǹ���һ�Ŵ���ɳ��(shadai)��һ
Щ��������ɳ��������
LONG);
	set("outdoors", "wuguan");
	set("exits", ([
		"west" : __DIR__"wg_wuchang1",
		"east" : __DIR__"wg_lang3",
	]));
	set("item_desc", ([
		"shadai" : "һ����ɳ�������������ϣ������кܶ���;���������������Ĵ�(da)��\n",
	]));
	set("objects", ([
		__DIR__"npc/wg_nvdizi" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_da", "da");
}
int do_da(string arg)
{
	object me;
	int costj, costq,c_exp,c_skill,skill_num;

	me = this_player();
	if (me->is_busy()) return notify_fail("��������æ���أ�\n");
	if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר��������\n");
	if ( !living(me)) return notify_fail("�㷢���ˣ�\n");
	if( objectp( me->query_temp("weapon")) )
		return notify_fail("ֻ�п��ֲ��ܴ�ɳ����\n");
	if ( !arg || arg != "shadai" )
	{
		message_vision("$N�����ָ�ڿ����Ҵ��ұ�һͨ�������ڹ�����\n",me);
		return 1;
	}
	costj = random((int)me->query("con"))+1;
	costq = random((int)me->query("str"))+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N�������ͣ�һ����С�ģ�ͷ������ǽ�ϣ�\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);       
	message_vision("$N���˸�������������Ȼ��һ����ɳ����ȥ��\n", me);
	c_exp=me->query("combat_exp");
	if ( (int)me->query("combat_exp") < 50000)
	{
		if (random(10)>6 )
		{
			skill_num=random(4);
			switch(skill_num)
			{
				case 0: c_skill=me->query_skill("finger",1);
						if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
							(int)me->query_skill("finger", 1) < 30 )
						{    
							me->improve_skill("finger", (int)(me->query("int") / 10));
							write(HIM"ɳ������ҡ�Σ��㲻֪������������Щ����ָ����\n"NOR);
						}
						else skill_num=1;
				case 1: c_skill=me->query_skill("leg",1);
						if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
							(int)me->query_skill("leg", 1) < 30 )
						{    
							me->improve_skill("leg", (int)(me->query("int") / 10));
							write(HIM"ɳ������ҡ�Σ��㲻֪������������Щ�����ȷ���\n"NOR);
						}
						else skill_num=2;
				case 2: c_skill=me->query_skill("claw",1);
						if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
							(int)me->query_skill("claw", 1) < 30 )
						{    
							me->improve_skill("claw", (int)(me->query("int") / 10));
							write(HIM"ɳ������ҡ�Σ��㲻֪������������Щ����צ����\n"NOR);
						}
						else skill_num=3;
				case 3: c_skill=me->query_skill("strike",1);
						if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
							(int)me->query_skill("strike", 1) < 30 )
						{    
							me->improve_skill("strike", (int)(me->query("int") / 10));
							write(HIM"ɳ������ҡ�Σ��㲻֪������������Щ�����Ʒ���\n"NOR);
						}
						else write(HIM"ɳ������Ŀ���������ҡ�Σ��������Ѿ�������Ӧ���ˣ�\n"NOR);					       
			}
		}
	
		me->add("potential",random(2));
		me->add("combat_exp",random((int)(me->query("str") / 10)));
	}
	return 1;
}
