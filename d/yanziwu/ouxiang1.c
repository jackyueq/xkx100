// Room: /d/yanziwu/ouxiang1.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "ź��С��");
	set("long", @LONG
ź��С������С�����硣С�����������������񣬺���ͷ�߶���
��ʱ�ͻ��������һƬ������������ɽׯ��С��Ĺ뷿��С�����з���
һ��С����������һ����̺�������������š��ı����䣬�벻��Ů��
���ҵĹ뷿��
LONG );
	set("exits", ([
		"northeast" : __DIR__"path17",
		"south"     : __DIR__"path18",
		"up"        : __DIR__"ouxiang2",
	]));
	set("objects", ([
		__DIR__"npc/youcao" : 1,
	]));
	set("coor/x", 1200);
	set("coor/y", -1230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}