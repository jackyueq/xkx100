// Room: /d/taohua/neishi1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "��Ӣ��");
	set("long", @LONG
����һ������ͨ��С�䣬�����ŷ��������ҡ����Ϲ��ż���ɽˮ
��ī���ֱʼ����پ����Լ���������֮�֡����ں�����ذ���һЩС��
�Σ�����Χ��һ��С�񼸣�����һ����ˮ���㣬ˮ��������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"woshi1",
		"west"  : __DIR__"fanting",
		"south" : __DIR__"zoulang2",
		"north" : __DIR__"neishi2",
	]));
	set("outdoors","taohua");
	set("objects", ([
		__DIR__"npc/yapu" : 1,
	]));

	set("coor/x", 9000);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}