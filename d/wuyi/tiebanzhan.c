// Room: /d/wuyi/tiebanzhang.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ʯ�¾��͡�ɫ�������������������ʮ���壬Ω���˷���
�����������Ů��֮�䣬�ɴ�������Ů��˵�������������Ƕ�����
�������ƻ�������Ů���������ˡ��˷����Ͳ������ˮ��ӳ�������ݺᡢ
ʯ�����ۡ�����ï���⾳���š����������ʯ�͡�ǧ�����֡���̡�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"2qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

