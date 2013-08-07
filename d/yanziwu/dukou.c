// Room: /d/yanziwu/dukou.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�軨��");
	set("long", @LONG
����������ɽׯ�Ĳ軨�ɡ�ɽׯ��������ƽ��ֿ���軨������ȴ��
ʶ������Ȼׯ��軨��Ұ��������ϧ�����軨����������ׯ�軨������
�껳�Ų���ģ����ûһ֦���þ���㡣
    �ɴ˿ɳ˴��뿪����ɽׯ��������ϵ��һβС��(zhou)��
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"north"  : __DIR__"chalin6",
		"south"  : __DIR__"chalin7",
		"east"   : __DIR__"path1",
	]));
	set("objects", ([
		__DIR__"npc/xiaocui" : 1,
	]));
	set("item_desc", ([
		"zhou" : "��������ɽׯ�ͺ�����ϵ��С�ۡ�����һ��������Ů�����ϵĿ���ֻҪ\n����(enter)�Ϳ��Գ����ˡ�\n",
	]));
	set("coor/x", 1200);
	set("coor/y", -1300);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_enter", "enter");
}
int do_enter(string arg)
{
	object ob ;
	string dir;
	if( !arg || arg !="zhou" ) 
	{
		tell_object(this_player() , "��ҪͶˮ��\n");
	 	return 1 ;
	}
	ob = this_player();
message_vision("����һ����������Ľ�����Ů����$N���ۣ������㣬����
�밶������ɽׯ��������Ұ��Զȥ��\n", ob);
	ob ->move(__DIR__"taihu") ;
	tell_object(ob, HIG "���ں���Ʈ�������ܿ������Ľ���������\n" NOR ) ;
	call_out("home", 10 , ob );
	return 1 ;
}
void home( object ob )
{
	tell_object(ob , "С��������������ؿ����ˡ�������С��������Ů������������\n" ) ;
	ob->move (__DIR__"hupan") ;
}
