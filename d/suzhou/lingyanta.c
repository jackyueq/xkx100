// Room: /d/suzhou/lingyanta.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",@long
���������������౦������ʼ������������Լ��ʮ���ף�Ϊ�߼���
�����������Ͽ�д�š����������������֡�
long);
	set("outdoors", "suzhou");
	set("exits",([
		"west"   : __DIR__"lingyansi",
//		"westup" : __DIR__"sdhyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 905);
	set("coor/y", -1120);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

