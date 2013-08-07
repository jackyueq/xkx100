// Room: /d/kunlun/shanmen.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������ɽ��");
	set("long",@long
��һ·���������ܴ���ɳ֮�࣬������ľ������������ʱ������
֦Ҷ�д�����������·�߲ݴ�ż��Ҳ�ܷ���һЩ���ŵ�Ұ�����������
���������컨��ʮ��ïʢ��������û�뵽��ɽ��ȴ��������ڣ������
Ϊһ��ǰ����һ��ɽ�ţ�д�š������ɡ��������֡�
long);
	set("exits",([
		"eastup"    : __DIR__"shanlu01",
		"southdown" : __DIR__"klshanlu",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/jiangtao" : 1,
		__DIR__"npc/kl-dizi1" :  1,
		__DIR__"npc/kl-dizi2" :  1,
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -120000);
	set("coor/y", 35000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
