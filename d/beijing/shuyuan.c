// Room: /beijing/shuyuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
��������Ժ�Ľ��ã�����������һ����Ⱦ��һλׯ�������������
��̫ʦ���Ͻ�ѧ���Ǿ��Ǿ��ǵĴ���������ˡ�������������������ѧ
��ѧ����һ�Ź��ⰻȻ���鰸���ڹ�������ǰ�棬���ϰ��ż���������
����װ�鼮���������������һ�����(shujia)�����ڶ��������ʯ�̣�
�����Ժ��ʷ���ƾá�ֵ��һ�����Ƕ�ڽ���ǰ��ڵ�ѧ��(xuegui)��
LONG );
	set("exits", ([
		"south" : __DIR__"di_an4",
	]));
	set("item_desc", ([
		"xuegui" : "�ս����������տ���Ŀ��ҳ��"  
			"\nͨ��ʱ�������ζ�����ʫ����" 
			"\n���������ʣ���ΰ�ʱ���ꡣ"
			"\nҹ���Խ���������Ҫ������\n\n"
			"��ѧ���ѧ����ʮ��\n",
	]));
	set("objects", ([
		__DIR__"npc/gu": 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	me->set_temp("mark/��", 0);
	return 1;
}
