// Room: /d/tiezhang/trdx.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;
#include <ansi.h>
string look_bei();

void create()
{
	object ob;
	set("short", HIR"��Ȼ��Ѩ"NOR);
	set("long", @LONG
��ʯ��ϵ��Ȼ���ɣ���֮�����˹������ʯ�Ҵ���ʮ������������
ȥ�����ڹ���ʮ��ߺ��ǣ��������ԣ���̬���в�ͬ���еĺ���ɢ����
�أ��е�ȴ�Ծ�������Σ�����Щ��̳��λ֮����ÿ�ߺ���֮�Զ�����
���У��������þߣ��䱦������ڴ�����һ��ʯ��(bei)��
LONG );
	set("exits", ([
		"out" : __DIR__"dong3",
	]));
	set("item_desc",([
		"bei"	 :       (: look_bei :),
	]));
	set("objects", ([
		__DIR__"obj/haigu" : 1,  
//		WEAPON_DIR"treasure/yuchang-jian" : 1,      
//		WEAPON_DIR"treasure/liquan-qiang" : 1,      
	]));
	set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -1800);
	set("coor/z", 70);
	setup();
	ob=new(WEAPON_DIR"treasure/yuchang-jian");
	if (ob->violate_unique())
	 destruct(ob);
	else
	  ob->move(this_object());
	ob=new(WEAPON_DIR"treasure/liquan-qiang");
	if (ob->violate_unique())
	 destruct(ob);
	else
	  ob->move(this_object());
  
}
string look_bei()
{
	return
	"\n      �ö�������Ʒ��\n"    
	"\n"RED"        ����Ī�֣�    \n"NOR
	"\n";
}