// Room: /d/baituo/sheyuan.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","��԰");
	set("long", @LONG
�����ǰ���ɽׯ����԰������ɽ�Զ��������£�����Ҫ�Ķ��ʾ���
�Զ��ߡ����������ߣ�ǽ��Ҳ�����ߣ�������Ҳ���´����ߣ���֦��
Ҳ�������ߣ������㲻�ľ���
LONG );
	set("exits",([
		"west"  : __DIR__"tuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		"/d/shenlong/npc/jinshe" :1,
		"/d/shenlong/npc/dushe" :1,
		"/d/shenlong/npc/fushe" :1,
		"/d/shenlong/npc/qingshe" :1,
		"/d/yanping/npc/wubushe" :1,
	]));
	set("coor/x", -49990);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
