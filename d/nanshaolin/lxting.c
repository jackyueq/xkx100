// Room: /d/nanshaolin/lxting.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", MAG"��ѩͤ"NOR);
	set("long", @LONG
����̨��ʰ�׶��ϣ���ǰ����һ��ͤ��һ��ĵ��á���ǰ������д
�š���ѩͤ���������֡�����������Ħͤ�����ڷ��蹩���Ħͭ��Ͷ�
�棬���棬���棬����������ഫ�������ɽ��Ժ��ѩͤ��ѩ�ϱ۵�
�ڴ�Ħ�洫�²��ĵط����������е�����������һλ��ü�������ɮ��
LONG );
	set("exits", ([
		"north"     : __DIR__"sblu-2",
		"southdown" : __DIR__"taijie",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/dayi" : 1,
	]));
	set("outdoors","nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6160);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if((!myfam || myfam["family_name"] != "��������" ||
		myfam["generation"] > 22 ) &&
		objectp(present("dayi dashi", environment(me))) &&
		dir == "north" ) 
	{
		return notify_fail("�����ʦ������ס�㹪��˵�����������Ǳ����صأ��Ǳ��ɸ߱����ӣ��������룡\n");
	}
	return ::valid_leave(me, dir);
}

