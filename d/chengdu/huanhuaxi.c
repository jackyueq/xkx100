// Room: huanhuaxi.c
// Date: Feb.14 1998 by Java

inherit ROOM;

void create()
{
	set("short", "佻�Ϫ");
	set("long", @LONG
������佻�Ϫ����С·�ϣ�佻�Ϫˮ��Ө��͸����������ԶԶ
�����ŵ�ˮ�������㡣���˯��ɢ����Ϫ��������ˮ��Ʈ����������
��Ƽ����Ƽ���в����޺��������ȥ��Ϫ��С·��Ϫ���������ƣ�
����û�㣬��Ʈ�ƺ���ʹ�˲�������������ν "���д���" ���ϲ�
���ۡ�
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"huanhuaxi1",		
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -2950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
