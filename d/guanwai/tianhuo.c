// /guanwai/tianhuo.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��鶺Ӷ����������ŷ���š��嶥��ӥ���ľ���ɽ����ʯ������
������أ�������ӥ��塣�����أ�������˫�⣬�б�һ�ߣ��л�Ȼ��
�ʡ����˲���˼��֮Ȥ�����ഫΪ������ˮ������ʯ���ɫ���������
�ᣬ��Ȥ������
LONG );
	set("exits", ([
		"south" : __DIR__"huagai",
		"west"  : __DIR__"longmen",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6200);
	set("coor/y", 5180);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}