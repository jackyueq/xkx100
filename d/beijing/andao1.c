// /d/beijing/andao1.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "��ػᰵ��");
	set("long", @LONG
����һ��������ĵص����������۵�ͨ��ǰ�������߶�����ǽ����
Լ������������ŵ���ص������������������ų�ʪ��������Ϣ������
�е�ʮ����ˬ��һ������վ�����������������������ڡ�
LONG );
	set("exits", ([
		"north"  : __DIR__"andao2",
		"south"  : __DIR__"andao3",
		"eastup" : __DIR__"neishi",
		"westup" : __DIR__"guancai2",
	]));
	set("objects", ([
		CLASS_D("yunlong") + "/xuanzhen" : 1
	]));
	set("coor/x", -212);
	set("coor/y", 4010);
	set("coor/z", -20);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("xuan", environment(me))) && 
		(dir == "east"||dir == "west") &&
		living(present("xuan", environment(me))))
	message("vision","������˰��Ź����ˡ�\n","/d/beijing/andao1");
	if(dir=="east")
		message("vision","һգ�ۣ������Ȼ����һ���ˡ�\n","/d/beijing/neishi");
	if(dir=="west")
		message("vision","һգ�ۣ������Ȼ����һ���ˡ�\n","/d/beijing/guancai2");
	return ::valid_leave(me, dir);
}
