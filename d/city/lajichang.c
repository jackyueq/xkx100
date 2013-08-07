// Room: workroom.c


inherit ROOM;
int do_drop(object me, object obj);
int all;
void create()
{
	set("short", "��������");
	set("long", @LONG
���������ݵĵ��������������й����ĵ��������
��������ӵ�����ط������Ա߾���һ�������ѣ���ʲô
����Ҫ�Ķ���������(drop)�ɡ�
LONG );
	set("exits", ([
		"up" : __DIR__"shilijie4",

	]));
	setup();
	seteuid(getuid());
}
void init()
{
	add_action("drop","drop");
}
int drop(string arg)
{
	object me=this_player();
	object obj, *inv, obj2;
	int i, amount;
	string item;
 	all=0;
 	if(!arg) return notify_fail("��Ҫ����ʲô������\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	if(sscanf(arg, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		if (sizeof(inv)>=20) all=1;
		for(i=0; i<sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		if (all!=1)
		  write("Ok.\n");
    else
      message_vision("$N�����ϵĶ������ӽ������ѡ�\n",me); 
	return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("������û������������\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	mixed no_drop;

	if( obj->query_temp("is_rided_by") == me)
		return notify_fail( obj->name() + "�������������š�\n");
	if( no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "���������������ⶪ����\n");
	if (obj->move(environment(me))) {
		if (all!=1)
		{
			if( obj->is_character() )
				message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
     	else if(obj->value())
				message_vision( sprintf("$N����һ%s$n��\n",	obj->query("unit")), me, obj );
   	 	else
   	 	{
   	 		message_vision(sprintf("$N��һ%s$n�ӽ������ѡ�\n",	obj->query("unit")), me, obj );
   	 	}
    }
  }
	if( !obj->value() && !obj->is_character())
	{
  	if (obj->query("value")) me->add("balance",1);
   	destruct(obj);    
  }
		return 1;
}
