// Room: /d/suzhou/zhenniang.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����Ĺ");
	set("long", @LONG
�Խ�ʯ������ǹ�����Ĺ������Ҳ�������ʷ֮�����佭�ϣ�
��ƭ���������¥������Ϊ����٣��Ծ���֮��������ͤ���ϣ�Ĺǰʯ
�̡���ꡱ���֣�Ĺ�ϱ��Ի��ܡ��ƴ��׾��׵�ʫ��ī�ͷ׷�Ϊ֮��ʫ��
��������֮���ҡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"sunwuting",
		"southwest" : __DIR__"shijianshi",
	]));
	set("coor/x", 810);
	set("coor/y", -1000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
