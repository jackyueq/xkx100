// Room: /d/yanziwu/qingyun.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����ׯ");
	set("long", @LONG
����������ׯ��ׯ����Ľ����������֮������Ľ�ݲ����¡��Ա�֮
������ʩ�����ľ�ѧ�����¡���Ľ�ݡ����Ƿ塱֮����Ľ��������
Ȼ�ǽ�������̩���ˡ�
    ׯ�������ϵ��һβС��(zhou)��
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"east"  : __DIR__"liangong",
	]));
	set("objects", ([
		CLASS_D("murong")+"/deng" : 1,
	]));
	set("item_desc", ([
		"zhou" : "��������ׯ�������ϵ��С�ۡ�����һ��������Ů�����ϵĿ���ֻҪ\n����(enter)�Ϳ����뿪�ˡ�\n",
	]));
	set("coor/x", 950);
	set("coor/y", -1500);
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
�밶������ׯ��������Ұ��Զȥ��\n", ob);
	ob ->move(__DIR__"taihu") ;
	tell_object(ob, HIG "���ں���Ʈ�������ܿ������Ľ���������\n" NOR ) ;
	call_out("home", 10 , ob );
	return 1 ;
}
void home( object ob )
{
	tell_object(ob , "С��������������ؿ����ˡ�������С��������Ů������������\n" ) ;
	ob->move (__DIR__"muti") ;
}
