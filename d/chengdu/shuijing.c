// Room: /d/chengdu/shuijing.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short", "ˮ��");
	set("long", @LONG
��һ���峺���׵�ˮ�������Դ���С�������м��������������ϴ
�£�һ��˵˵ЦЦ�����и����ˣ�������������Ͱ��ˮ���������Ƶس�
����ȥ�����������ȿ�ˮ��
LONG	);
	set("resource/water", 1);
	set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"dongjie3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8020);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

