// Room: /d/taohua/hetang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>;
inherit ROOM;
int do_ride();

void create()
{
	set("short", "����");
	set("long", @LONG
�������۵�ת�����֣���ǰ����һ��Ƭ���������а���ʢ�ţ�����
������Ҷ���һ��Сʯ�̴����������룬���洩������ͨ�����һ
�����ᣬ������һƬ���֡�������һ�԰׵�(diao)������Ϸ����������
��׳��
LONG
	);
	set("exits",([
		"north" : __DIR__"dating",
		"south" : __DIR__"jicui",
	]) );
	set("item_desc", ([
		"diao" : "һ�԰׵���չ�����ɡ�������һ����ĵ��ӣ�\n"
		"����(ride)�Ϳ��Էɵ���ԭ��\n",
	]));
	set("no_clean_up",0);
	set("outdoors","taohua");
	set("coor/x", 9010);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_ride", "ride");
}
int do_ride()
{
	mapping myfam;
	object ob = this_player();
	myfam = (mapping)ob->query("family");
	if(!myfam || myfam["family_name"] != "�һ���")
	{
		message_vision("$NһԾ������˰׵�ֻ���׵����쳤ণ�ͻȻ��Ȼһ��......\n"HIR"���$Nˤ�˸��������ף�\n"NOR"�����׵��$N��������Ȥ����ֻ��ʶ�һ����ĵ��ӡ�\n",ob);
		ob->receive_damage("qi",50);
		ob->receive_wound("qi",50);
		return 1;
	}
	if( (int)query("sb_ride") ) 
		return notify_fail("���ڰ׵���æ�ţ����һ���ٳ�����\n" ) ;
	add("sb_ride",1) ;
	message_vision("$NһԾ������˰׵�ֻ���׵����쳤ণ�ͻȻչ��߷ɡ�\n\n����һ��һ�����ν�����С������������\n" , ob );
	ob->move("/d/taohua/lantian") ;
	tell_object(ob,CYN"\n�㲻�ϵط�ѽ�ɣ���ˮǧɽ����Ʈ�� ......\n\n" NOR);
	call_out("taohua", 3 , ob );
	add("sb_ride",-1) ;
	return 1 ;
}
void taohua( object ob )
{
	tell_object(ob, "�����ڷɵ�����ԭ���׵�����������\n\n"  ) ;
	ob -> move ("/d/guiyun/dayuan");
}
