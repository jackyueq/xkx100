// Room: /d/guiyun/zoulang5.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
���Ǵ�����ͨ�����䳡�����ȡ������������������ۣ�����������
�ʻ��οգ���Ŀ���⣬���������˻�����
LONG );
	set("exits",([
		"east"  : __DIR__"zoulang4",
		"south" : __DIR__"zoulang6",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}
