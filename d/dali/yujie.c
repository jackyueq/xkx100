//Room: /d/dali/road1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
������Ǵ���Ļʹ�ǰ���֣����湬���ϵ��Ҷ�д�š�ʥ�ȹ���
�������֡��������۶������ѵ������³���Ϊɮ�ˣ�����ľ�����
�¾Ͷ����������������ˡ�
LONG);
	set("outdoors", "dali");
        set("no_fight",1);
	set("objects",([
	    __DIR__"npc/weishi2": 1,
            CLASS_D("dali")+"/zhudanchen": 1, 
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"paifang",
	    "north" : __DIR__"gongmen",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40010);
	set("coor/y", -71000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}