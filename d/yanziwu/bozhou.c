//ROOM: /d/yanziwu/bozhou.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������");
	set("long",@LONG
һƬ«έ�����״����ֳ�һ�����룬��С��ֻ�����ſ����⻨��Ҷ
��������ˮ����ͨ�˴�ɴ˿ɳ˴��뿪�����롣������ϵ�ż�βС��
(zhou)��
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"east"  : __DIR__"pindi",
	]));
	set("item_desc", ([
		"zhou" : "����������ͺ�����ϵ�ĸ�ɫС�ۡ����ϵĿ���ֻҪ����(enter)�Ϳ��Գ����ˡ�
��ɫС��(white)  : ����
��ɫС��(green)  : ǰ������ׯ
��ɫС��(red)    : ǰ����ϼׯ
��ɫС��(yellow) : ǰ�����ׯ
��ɫС��(black)  : ǰ����˪ׯ
\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", 800);
	set("coor/y", -1520);
	set("coor/z", 10);
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
	if( !arg || (arg!="white" && arg!="red" && arg!="green" && arg!="black" && arg!="yellow")) 
	{
		tell_object(this_player() , "��ҪͶˮ��\n");
	 	return 1 ;
	}
	ob = this_player();
message_vision("����һ����������Ľ�����Ů����$N���ۣ������㣬�����밶������
�뽥������Ұ��Զȥ��\n", ob);
	ob ->move(__DIR__"taihu") ;
	tell_object(ob, HIG "���ں���Ʈ�������ܿ������Ľ���������\n" NOR ) ;
	call_out("home", 10, ob, arg);
	return 1 ;
}
void home(object ob, string arg)
{
	tell_object(ob , "С��������������ؿ����ˡ�������С��������Ů������������\n" ) ;
	switch (arg)
	{
		case "white"  : ob->move (__DIR__"hupan"); break;
		case "red"    : ob->move (__DIR__"chixia"); break;
		case "green"  : ob->move (__DIR__"qingyun"); break;
		case "black"  : ob->move (__DIR__"xuanshuan"); break;
		case "yellow" : ob->move (__DIR__"jinfeng"); break;
	}
}