// Room: /d/tiezhang/wztang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
string look_bian();

void create()
{
	set("short", HIY"��ָ��"NOR);
	set("long", @LONG
����һ����ȫ�û��������ɵĴ�����͸��������˵ĺ�����������
��û�д������Ե���ɭ�ڰ������Ե�ǽ���ϲ������ͻ�ѣ�ɢ�������
�Ĺ������ž��Ĵ����в�ʱ��������ž��ȼ���������������аڷ���
�����ı��������Է�����ʮ�������ӣ�ֻ���������д���ʱ�������Ż�
�������벿�����顣�������ǽ�Ϲ���һ���ƽ�ĺ���(bian)��������
һ��С��ͨ����档
LONG	);
	set("item_desc", ([ 
		"bian" : (: look_bian :),
	]));
	set("exits", ([ 
		"east"      : __DIR__"zoulang1",
		"west"      : __DIR__"zoulang2",
		"north"     : __DIR__"hxfang",
		"southdown" : __DIR__"guangchang",
	]));
	set("objects", ([ 
		CLASS_D("tiezhang")+"/qqren" : 1,
		__DIR__"npc/xiaotong" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
	
}
string look_bian()
{
	return
	"\n"HIY
	"          ####################################\n"
	"          ####                            ####\n"
	"          ####    ��    ָ    ��    ��    ####\n"  
	"          ####                            ####\n"
	"          ####################################\n"NOR;
	"\n";
}