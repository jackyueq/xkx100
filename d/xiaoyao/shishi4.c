// shishi4.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
����һ�����µ�����ʯ�ң�������Ըо��õ���ֻ��ǿ�ҵ�ɱ����
�Լ�����ص׵�һЩ���ŵ���ζ����΢���ĵƹ��£��㾹Ȼ�����и���
վ������������º�����·��
LONG );
	set("exits", ([
		"up" : __DIR__"fangjian2",
		"down" : __DIR__"shishi5",
	]));
	set("objects",([
//		__DIR__"npc/qingyun" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21030);
	set("coor/z", -50);
	setup();
}

/*int valid_leave(object me,string dir)
{
        if(dir=="down" && (!me->query("family") || (me->query("family/master_id")!="xiaoyao zi")) && present("qingyun",environment(me))) 
             return notify_fail("����һ��������ס�����ȥ·��\n");
        return ::valid_leave(me,dir);
}*/