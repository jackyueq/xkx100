// Room: /d/lingxiao/iceroad3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
�������������߶��ܰ����������Ǳ����������������ǵļ�������
�߹�ȥ�����������ǵĸ���֮�ة���ѩɽ�ɵ������������ˣ��������
���ܣ��Ĵ������������ӡ�
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"iceroad2",
		"north" : __DIR__"meiroad1",
		"west"  : __DIR__"car",
		"east"  : __DIR__"jianyuting",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -31000);
	set("coor/y", -8900);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

