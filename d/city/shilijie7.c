// Room: /yangzhou/shiliji7.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ʮ�ﳤ��");
	set("long",@LONG
��������̻����µ�ʮ�ﳤ�֡����ֿ����ʮ�ɣ���ש�̵أ�����
һ��йˮ�������������л����������������Ҷ��С������ǹٺӣ�����
��������������ң���Ӱˮ�棬ҡҷ���С�������һ�����뽭��������
��ȥ����ݡ�������һ�Ҵ����̣�����������������Զ��������������
ͨ�����Ĺ㳡������һֱ�߾ͳ������ˡ�
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"datiepu",
		"east"  : "/d/wuguan/wg_guanmen",
		"south" : __DIR__"nanmendajie",
		"north" : __DIR__"shilijie6",
	]));
	set("objects", ([
		CLASS_D("shaolin") + "/tuoboseng" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
