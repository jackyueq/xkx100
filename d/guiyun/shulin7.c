// Room: /d/guiyun/shulin7.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long",@LONG
����һƬС���ֵ�����������̲�����ï�ܵ������š���Ҷ��
��϶��ż������һֻС�񱻾�������ʮ�־��š�����ʱ���ж��߳�û��
��ò�Ҫ�ڴ˾�����
LONG
);
	set("exits",([
		"south" : __DIR__"shulin5",
	]) );
	set("objects",([
		__DIR__"npc/snake" : 2,
	]));  
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}

