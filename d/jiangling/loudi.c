//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "¥��");
	set ("long", @LONG
һ������С¥�������еͰ���Χǽ��ǽ�����˼�����������¥�Ĵ�
���Ϸ���һ���ɫǾޱ��ֻ�����仨������ήл��һ��紵���������
�����ɢ��Ʈ�ɣ�����һ������֨�Ʒɹ����о�����˵������������С
���ڹ��߻谵�����Կ��ü��ݽ���խС��¥�ݡ�
LONG);

	set("exits", ([ 
		"up"   : __DIR__"loudao",
		"west" : __DIR__"feiyuan",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1460);
	set("coor/y", -2039);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
