// Room: /binghuo/jiangmian1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "Ǯ������");
	set("long", @LONG
ֻ��������������Ǯ������ҹ���������������ף������������
���͵ر�����������˵����������û�����⿴ʱ��ֻ����������һ
��͸���ĸ�ǽ���������ﱻ��û�ھ���֮���ˡ�
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

