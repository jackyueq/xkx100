// Room: /d/taishan/dongling.c
// Last Modified by Winder on Aug. 25 2001

inherit RESTROOM_OUT;

void create()
{
	set("short", "�����");
	set("long", @LONG
������̩ɽ�ɵĸ����صء����ڲ������£���������̩ɽ�ɿ���
��ʦ�����������λ�ͻ���������¯������������㣬����������
����ɢ����һ��̴��ζ��
    ���������̩ɽ�ɵ�����������Ϣ�䡣
LONG );
	set("exits", ([
		"east"    : __DIR__"riguanroad2",
		"westup"  : __DIR__"riguanroad1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 390);
	set("coor/y", 770);
	set("coor/z", 190);
	set("door_name","����");
	set("door_dir","north");
	set("restroom",__DIR__"dongling1");
	set("open_door_msg","���Ϲ��˸����ӣ���Ϣ�ҡ�\n");
	set("inside_msg",   "���Ϲ��˸����ӣ�����һ�Ρ��������죡\n");
	set("no_one_msg",   "���Ϲ��˸����ӣ���Ϣ�ҡ�\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
