// Room: /d/wuyi/yinpingfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������山�ࡣ�ұ��������Ծ����֡��ɷ��硱����ʾ�����
���˼�Ľ綨���ɡ����顱���ִ������ݣ��ġ����ء������ǡ��ɷ��硱
�ˡ���ʯ�����ϣ�����������������ġ������ѡ������ϡ���������ֱ
��嶥��
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"westdown" : __DIR__"yunwo",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -5010);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

