// /d/shenlong/fengding �嶥
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�嶥");
	set("long", @LONG
��������������߷壬����ȴ���ǿ���վ�ڷ嶥����ĿԶ������
�����ܾ���ε������ա�ãã�Ĵ󺣡���ͻȻ�����Լ��Ƕ�ô����С��
����׺�֮һ�ڡ��Ա�һȺ����������Ѳ���ţ�ż����������س�����
���ۡ������ǳ��ȣ���������ɽ��ɽ����������һ��ͨ���ɽ��С·��
·��С���ƺ��ߵ��˲��ࡣ
LONG
	);
	set("exits", ([
		"east"      : __DIR__"changlang",
		"northdown" : __DIR__"lin1",
		"southdown" : __DIR__"shandao",
	]));
	set("outdoors", "shenlong");
	set("objects", ([
		CLASS_D("shenlong")+"/hesheng" : 1,
	]));

	setup();
	replace_program(ROOM);
}

