// Room: /d/guiyun/qianting.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","ǰ��");
	set("long",@LONG
���ǹ���ׯ��ǰ����ƽ���д����˶���������С����г��軪����
����������������˼��
LONG
);
	set("objects",([
		__DIR__"npc/zhuangding1" : 2,
	]));  
	set("exits",([
		"east" : __DIR__"dayuan",
		"west" : __DIR__"zhongting",
	]) );
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}
