// Room: /yangzhou/changchunling.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
�������������򽭽�ɽ���׳�С��ɽ����ʱΪʹǬ¡��������ֱ��
ƽɽ�ã��㿪�����������ºӣ��ڳ������ѻ�����С��ɽ���������滷
ˮ�����ϱ�ֲ��÷�������������磬��Ի"÷�봺��"��������׫���ƣ�
����ȡ����һ�ǿ������ݣ�������ɽ����ϧ��С����һ�Բ������Ӽ�
����һ��ԭ����ɽˮ�辰������ʯ���衣
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"northdown" : __DIR__"balongqiao",
		"southdown" : __DIR__"xiaohongqiao",
		"southeast" : __DIR__"qinshi1",
		"westdown"  : __DIR__"changchunqiao",
		"east"      : __DIR__"qishi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 110);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}