// Room: /d/emei/caodi.c
inherit ROOM;
int do_search();
void end(object);
void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������ǹŵ����е�һƬ�ݵ��ˡ�����Ұ�ݴ������߹���ͷ��ż����С��
�Ӳ��д����������ط���ɭ�ֲ�����Χ��һ��Ƭ��ɭɭ�����֡�
LONG
	);
	set("objects", ([
		CLASS_D("emei")+"/fengling" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
	    "south" : __DIR__"gudelin3",
	]));
	set("coor/x", -6130);
	set("coor/y", -1070);
	set("coor/z", 50);
	setup();
}
void init()
{
	add_action("do_search","search");
}
int do_search()
{
	object me = this_player();
	object ob ;
	int jing;
	if( me->is_busy() ) return notify_fail("����һ��������û������ء�\n");
	if(jing<30) return notify_fail("���޷����о����鿴��\n");
	message_vision("$N��ʼ�鿴�����һ��һľ��ϣ�����ҵ�һ�ò�ҩʲô�ġ�\n",me);
	me->start_busy(2);
	me->receive_damage("jing", 10);
	call_out("end",3,me);
	return 1;
}
void end(object me)
{
	object ob;
	switch(random(10))
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			message_vision("$N���˸����������ʲô��û���ҵ���\n",me);
			break;
		default: ob=new(__DIR__"obj/caoyao");
			ob->move(me);
			message_vision("$N�ҵ���һƬ��ҩ������$N�����ϡ�\n",me);
			break;
	}
}