// /d/shenlong/cancel_pk.h
// Last Modified by winder on Jul. 12 2002

void cancel_pk()
{
	mapping pkjob;
	object pker;
	string *v_list, v_id, p_id;
	int i, punish;

	if( !(pkjob = query("pkjob")) ) return;

	v_list = keys(pkjob);
	for(i = 0; i < sizeof(v_list); i++)
	{
		v_id = v_list[i];
		p_id = pkjob[v_id];

		if( !find_player(v_id) && (pker=find_player(p_id)) )
		{
			tell_object(pker, "\n��Ҫ׷ɱ�����Ѿ��뿪�ˡ�\n");
			pker->delete("sgjob");
			punish = 3 + random(6);
			pker->add("sg/failure", punish);
			pker->add("sg/exp", -punish);
			map_delete(pkjob, v_id);
			set("pkjob", pkjob);
		}
		else
			if( !pker )
			{
				pker = new(USER_OB);
				pker->set("id", p_id);
				if( pker->restore() )
				{
					pker->delete("sgjob");
					punish = 1 + random(6);
					pker->add("sg/failure", punish);
					pker->add("sg/exp", -punish);
					pker->save();
				}
				destruct(pker);				
				map_delete(pkjob, v_id);
				set("pkjob", pkjob);
			}
	}
}
