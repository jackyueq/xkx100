// Room: /d/suzhou/yingxiaoting.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "ӭЦͤ");
        set("long",@long
����������ɽ��ɽ�ϵ�һ��Сͤ�ӣ���ɽ����ɽ���ο͵������ﶼ
ЪЪ�š�����ɽ�¾�ɫ��Զ��һƬ�̲�����ˮ��֮�䣬������⣬ɷ��
���ˡ�
long);
	set("outdoors","suzhou");
	set("objects",([
		__DIR__"npc/seng" : 1,
	]));
	set("exits",([
		"westdown" : __DIR__"lingyanshan",
		"southup" : __DIR__"shiyuan",
	]));
	set("coor/x", 900);
	set("coor/y", -1100);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
