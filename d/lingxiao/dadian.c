// Room: /d/lingxiao/dadian.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
string look_duilian();
#include <ansi.h>;
void create()
{
	set("short", "������");
	set("long", 
"������������ǵĸ���֮�ة�������������������������кδ�
�£����Ŷ����ڴ��ټ����ˣ�����ʩ�������ǽ�ϣ�����һ�����˵�
Ф���ǵ��������Ǵ�����ʦ���������������Ͽ���һ������(lian)��
�Աߵı������Ϸ����˺��������ĳ������ö����һ���ң������ĸ���
�֡�"HIB"

                       ÷ѩ����
\n"NOR);
        set("valid_startroom", 1);
	set("item_desc",([
		"lian" : (: look_duilian :),
	]));
	set("exits", ([
		"east"  : __DIR__"fudian2",
		"west"  : __DIR__"fudian1",
		"north" : __DIR__"qianyuan",
		"out"   : __DIR__"meiroad1",
	]));
	set("objects", ([
		__DIR__"npc/lu" : 1,
		__DIR__"npc/dizi" : 3,
	]));
	set("coor/x", -31000);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	"/clone/board/lingxiao_b"->foo();
} 

string look_duilian()
{
	return
	"\n"
	"    ����������������������������������\n"
	"    ������������������������  ��������\n"
	"    ������������          ÷����������\n"
	"    ������������          ������������\n"
	"    ������������          �㡡��������\n"
	"    ������������          �ԡ���������\n"
	"    ����������ĥ          �ࡡ��������\n"
	"    ������������          ������������\n"
	"    ������������          ������������\n"
	"    ����������������������������������\n"
	"    ����������������������������������\n\n";
}

