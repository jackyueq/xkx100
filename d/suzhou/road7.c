// Room: /d/suzhou/road7.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "���ϴ��");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������
�Ҷ��������������һЩС��̯���ƺ���һ�����С�����ͨ������ɽ��
�ϱߵ���ʯ���ͨ����ߡ�
long);
	set("outdoors", "suzhou");
	set("exits",([
		"north" : __DIR__"lingyanshan",
		"south" : __DIR__"road6",
	]));
	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
