// Room: /d/taohua/hill.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "Сɽ");
	set("long", @LONG
һ����ɽͷ����ͷ�����ǰ��Ȼ���ʣ�����ɽ������һ��Ƭ���һ�
�ԣ����ڻ�������Լ¶���˼���ͥԺ�ķ��ܣ��ƺ�����һƬ���ŵĽ���
���Ǳߡ��򿿺���һ����ȥ��������ɽʱ��ŵ���ʯ�Ѿ����ŵ��ˣ���
��Ҳ�ز��������ˡ��������߸���һ��Сɽ�壬ʮ���վ���
LONG
	);
	set("exits", ([ 
		"northdown" : __DIR__"taohua1",
		"eastup" : __DIR__"hill1",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 8500);
	set("coor/y", -4690);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
