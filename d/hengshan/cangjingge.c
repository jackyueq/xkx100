// Last Modified by Sir on May. 22 2001
//Room: cangjingge.c �ؾ���

inherit ROOM;
void create()
{
	set("short","�ؾ���");
	set("long",@LONG
������Ǻ�ɽ�ɵĲؾ����ˡ����ܶ����������飬�߼��������ܡ�
��������һ�Ŵ����ӣ����Ϸ��˼����𾭡���λСʦ̫������ר���ж���
LONG);
	set("objects", ([	     
		__DIR__"obj/fojing1"+random(2) : 1,	     
	]));
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"byaeast", 
	]));
//	set("no_clean_up", 0);
	set("coor/x", 60);
	set("coor/y", 3210);
	set("coor/z", 100);
	setup();
}

