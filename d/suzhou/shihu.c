// Room: /d/suzhou/shihu.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long",@long
ʯ����̫����һ����½֧����λ�����ݳ��ϴ���ʱ��Խ�����⣬��
��ɽ´����ʯ������ͨ���գ�����ʯ�������������Ϸ�ɽ��ɽ��������
���������ı�����ߴ��Խ���ţ������е���Խ����½��Խ��Ϫ����
������ʼ��������ĩ����д��š�
long);
	set("outdoors", "suzhou");
	set("exits",([
		"south" : __DIR__"tianpingshan",
		"west" : __DIR__"xingchunqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -1080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
