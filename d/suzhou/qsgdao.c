// Room: /d/suzhou/qsgdao.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������
�Ҷ��������������һЩС��̯���ƺ���һ�����С�
long);
	set("outdoors", "suzhou");
	set("exits",([
		"north"     : __DIR__"qsgdao1",
		"southwest" : __DIR__"tianpingshan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
