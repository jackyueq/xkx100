// Room: /d/wuxi/kuaxiqiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "��Ϫ��");
	set("long", @LONG
��Ϫ���׳����ŵ��ţ��ֳ������ţ����µ���Ϫ����һ�ȳ�Ϊ����
�ı�ơ�������ԭ���������ֶ̼�Ҫ�Ӵ˽��������ǡ�������Ҳ�ǵ���
�������Ļ�ɽȥ��·��������ȥ��һ�������������ͷ��·����������
�������ﲻ��������������Ϫ�š�
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"east" : __DIR__"westgate",
		"west" : __DIR__"road14",
	]));
	set("no_clean_up", 0);
	set("coor/x", 300);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}