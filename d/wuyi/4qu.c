// Room: /d/wuyi/4qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ɲ������̶���ഫԭ�������ݷ���ʮ��������Ϊ����
�����˺��޹���������ִ���Ǳ���ɱ��š�С��ʹ��ǰ�ǣ��������Ǿ�
����һ����·���Ӵ��츣���ա����䡶�������衷Ի����������������
��ʯ�ң��һ���¶����맣��𼦽а����˼���������ɽˮ��̶��������
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"shijianshi",
		"southup"   : __DIR__"dazangfeng",
		"northeast" : __DIR__"3qu",
		"southwest" : __DIR__"5qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

