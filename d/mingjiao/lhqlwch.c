// lhqlwch.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
���߽����һ�������䳡����������Ľ����ǲ��������໥�д���
�������Ǵ��������Ƶķ��𻤾ߣ���ѧϰʹ�û�ߺ���׼����������
��ڵ�ԭ�ͣ�����ȼ�������ޱȡ�
LONG );
	set("exits", ([
		"east" : __DIR__"lhqyuan",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52040);
	set("coor/y", 1000);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}