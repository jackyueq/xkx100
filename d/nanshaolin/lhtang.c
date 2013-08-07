// Room: /d/nanshaolin/lhtang.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"�޺���"NOR);
	set("long", @LONG
����ǰ��һ���ܴ��Ժ�䣬��Χ�ø�ǽΧס��Ժ���Ҷ���д�š���
���á��������֡����������ֵ�����ϰ���Ż����书�����ڡ��кܶ���
���ɮ�˽���������Ժ�ڴ����������������������
LONG );
	set("exits", ([
		"east" : __DIR__"stoneroad4",
		"west" : __DIR__"lwc1",
	]));
	set("outdoors", "nanshaolin");
	set("objects",([
		CLASS_D("nanshaolin")+"/daji" : 1,
	]));
	set("coor/x", 1800);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
}
void init()
{ 
	add_action("do_jump","zong");
}
int do_jump(string arg)
{ 
	object me = this_player();   
	if (arg!="bian") return 0;  
	if(me->query_skill("dodge",1)<130)  
		return notify_fail("�㹦���������������Ҷ\n");  
	message("vision",me->name()+"�������У�ƽ�հ������ɣ����������Ҷ�֮��\n",this_object());
	me->move(__DIR__"bianhou");
	me->set_temp("baitie",1);  return 1; 
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "��������") && dir == "west" &&
		objectp(present("xuanku dashi", environment(me))))
		return notify_fail("�󼲴�ʦ�ȵ����޺����˱��ɵ���ϰ��֮������Ǳ��ɵ��ӣ��������ڡ�\n");
	return ::valid_leave(me, dir);
}
 
